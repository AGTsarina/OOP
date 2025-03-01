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
    Color * pixels;
    UInt size;
public:
    BMP(fstream &bmp_file):header(bmp_file, true){
        MemoryInfoHeader mem_info(bmp_file);//, true);
        this->info = mem_info.info;
        size = info.width * info.height;
        pixels = new Color[size];
        bmp_file.read(reinterpret_cast<char*>(pixels), 
        size * sizeof(Color));
    }
    void ReplaceColor(Color toReplace, Color color){
        // toReplace <- color
        for(int i=0; i<size; i++){
            if(pixels[i] == toReplace){
                pixels[i] = color;
            }
        }
    }
    void Save(const char * filename){
        std::ofstream file(filename, std::ios::binary);
        header.save(file);
        MemoryInfoHeader mem_info(info);        
        file.write(mem_info.data, sizeof(InfoHeader));
        file.write(reinterpret_cast<char *>(pixels), size * 3);
    }
    void FillRect(Rect rect, Color color){
        int w = rect.x + rect.width;
        int h = rect.y + rect.height;
        for(int j=rect.x; j<w; j++){
            for(int i=rect.y; i<h; i++){
                pixels[i * info.width + j] = color;
            }
        }
    }
};
