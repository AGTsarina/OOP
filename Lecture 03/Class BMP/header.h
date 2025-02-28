#pragma once
#include <fstream>
using std::fstream;
using Uint = unsigned int;

struct Header
{
    char signature[2];
    Uint fileSize;
    Uint reserved;
    Uint dataOffset;

    Header(fstream &bmp_file){
        bmp_file.read(this->signature, 2);
        bmp_file.read(reinterpret_cast<char*>(&this->fileSize), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->reserved), 4);
        bmp_file.read(reinterpret_cast<char*>(&this->dataOffset), 4);
    }    

     Header(fstream &bmp_file, bool fromBinaryArray){
        char tmp[14];
        bmp_file.read(tmp, 14);
        this->signature[0] = tmp[0];
        this->signature[1] = tmp[1];
        this->fileSize = *(reinterpret_cast<int*>(tmp + 2));
        this->reserved = *(reinterpret_cast<int*>(tmp + 6));
        this->dataOffset = *(reinterpret_cast<int*>(tmp + 10));        
    }
};

