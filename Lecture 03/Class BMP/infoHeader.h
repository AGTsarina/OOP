#pragma once
#include <fstream>
// #include "memory.h"
using std::fstream;
using UInt = unsigned int;
using UShort = unsigned short;


struct InfoHeader{
    UInt size;              // Size of InfoHeader =40 
    UInt width;             // Horizontal width of bitmap in pixels
    UInt height;            // Vertical height of bitmap in pixels
    UShort planes;          // Number of Planes (=1)
    UShort bitsPerPixel;    // Bits per Pixel used to store palette entry information. This also identifies in an indirect way the number of possible colors. Possible values are:
    UInt compression;       // Type of Compression  

    UInt imageSize;         // (compressed) Size of Image 

    UInt xPixelsPerM;       // horizontal resolution: Pixels/meter
    UInt yPixelsPerM; 	    // vertical resolution: Pixels/meter
    UInt colorsUsed; 	    // Number of actually used colors. For a 8-bit / pixel bitmap this will be 100h or 256.
    UInt importantColors; 	// Number of important colors 

    InfoHeader(fstream &bmp_file){
        bmp_file.read(reinterpret_cast<char*>(&this->size), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->width), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->height), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->planes), 2);
        bmp_file.read(reinterpret_cast<char*>(&this->bitsPerPixel), 2);
        bmp_file.read(reinterpret_cast<char*>(&this->compression), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->imageSize), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->xPixelsPerM), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->yPixelsPerM), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->colorsUsed), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->importantColors), 4);
    }
    InfoHeader(){
        
    }

    /*InfoHeader(fstream &bmp_file, bool fromBinaryArray){
        MemoryInfoHeader mem(bmp_file);
        *this = mem.info;
    }*/
};



