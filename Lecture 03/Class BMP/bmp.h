#include "header.h"
#include "infoHeader.h"

using byte=unsigned char;

struct Color{
    byte blue, green, red;
};

union MemoryInfoHeader{
    InfoHeader info;
    char data[40];

    MemoryInfoHeader(fstream &bmp_file){        
        bmp_file.read(data, 40);
    }
};

class BMP{
    Header header;
    InfoHeader info;
    Color * pixels;
public:
    BMP(fstream &bmp_file):header(bmp_file, true){
        MemoryInfoHeader mem_info(bmp_file);//, true);
        this->info = mem_info.info;
        pixels = new Color[info.width * info.height];
        bmp_file.read(reinterpret_cast<char*>(pixels), 
        info.width * info.height * sizeof(Color));
    }
};
