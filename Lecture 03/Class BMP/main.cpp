#include <fstream>
#include <iostream>

#include "bmp.h"

using std::fstream, std::ifstream, std::ofstream, std::ios;
using std::cout;



int main(){    
    fstream bmp_file("bmp_24.bmp", ios::binary|ios::in|ios::out);
    BMP bmp(bmp_file);
    return 0;
}