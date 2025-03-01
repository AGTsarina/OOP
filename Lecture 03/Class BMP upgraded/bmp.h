#pragma once
#include <fstream>
#include "header.h"
#include "infoHeader.h"
#include "rect.h"

using byte=unsigned char;

struct Color{
    byte blue, green, red;
    bool operator==(Color&color){
        return blue == color.blue && 
        red == color.red && green == color.green;
    }
    UInt distSqr(const Color & color) const{
        UInt dRed = red - color.red;
        UInt dGreen = green - color.green;
        UInt dBlue = blue - color.blue;
        return dRed * dRed + dGreen * dGreen + dBlue * dBlue;
    }
};

union MemoryInfoHeader{
    InfoHeader info;
    char data[40];

    MemoryInfoHeader(fstream &bmp_file){        
        bmp_file.read(data, 40);
    }
    MemoryInfoHeader(InfoHeader &info){
        this->info = info;
    }
};

class BMP{
    Header header;
    InfoHeader info;
    byte * pixels;
    UInt size;
    UInt padding;
public:
    BMP(fstream &bmp_file):header(bmp_file, true){
        MemoryInfoHeader mem_info(bmp_file);//, true);
        this->info = mem_info.info;
        padding = (4 -  (info.width * sizeof(Color)) % 4) % 4;
        size = info.width * info.height *sizeof(Color) + padding * info.height;
        pixels = new byte[size];
        bmp_file.read(reinterpret_cast<char*>(pixels), 
        size);
    }
    void ReplaceColor(Color toReplace, Color color){
        // toReplace <- color
        for(int i=0; i<info.height; i++){
            // адрес начала i-ой строки
            auto addr =  i * (sizeof(Color) * info.width + padding);
            // совмещаем в памяти указатель на массив цветов 
            // с массивом байт, начиная с pixels[addr];
            Color * line = reinterpret_cast<Color*>(pixels + addr);
            for(int j=0; j<info.width; j++){
                if(line[j].distSqr(toReplace) < 50000){
                    line[j] = color;
                }
            }
        }
    }
    void Save(const char * filename){
        std::ofstream file(filename, std::ios::binary);
        header.save(file);
        MemoryInfoHeader mem_info(info);        
        file.write(mem_info.data, sizeof(InfoHeader));
        file.write(reinterpret_cast<char *>(pixels), size);
        
    }
    void FillRect(Rect rect, Color color){
        int w = rect.x + rect.width;
        int h = rect.y + rect.height;
        for(int i=rect.y; i<h; i++){
            // адрес начала i-ой строки
            auto addr =  i * (sizeof(Color) * info.width + padding);
            // совмещаем в памяти указатель на массив цветов 
            // с массивом байт, начиная с pixels[addr];
            Color * line = reinterpret_cast<Color*>(pixels + addr);
            for(int j=rect.x; j< w; j++){
                line[j] = color;                
            }
        }
    }

    unsigned long GetLineAddress(int i)
    {
        return i * (sizeof(Color) * info.width + padding);
    }

    Color * GetLine(int i){
        // адрес начала i-ой строки
        auto addr =  GetLineAddress(i);
        return reinterpret_cast<Color*>(pixels + addr);
    }

    void Copy(BMP &image){  
        Color white{255,255,255};  
        for(int i=0; i<image.info.height; i++){            
            // совмещаем в памяти указатель на массив цветов 
            // с массивом байт, начиная с pixels[addr];
            Color * line = GetLine(i);
            Color * image_line = image.GetLine(i);
            for(int j=0; j< image.info.width; j++){
                if (!(image_line[j] == white)){
                    line[j] = image_line[j];               
                } 
            }
        }
    }
};
