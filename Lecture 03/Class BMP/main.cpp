#include <fstream>
#include <iostream>

#include "bmp.h"

using std::fstream, std::ifstream, std::ofstream, std::ios;
using std::cout;



int main(){    
    fstream bmp_file("maze.bmp", ios::binary|ios::in|ios::out);
    BMP bmp(bmp_file);
    // замена цвета
    bmp.ReplaceColor(Color{255,0,0}, Color{255,127,127});
    // нарисовать прямоугольник color цвета
    bmp.FillRect(Rect{10, 10, 50, 20}, Color{255,255,255});
    bmp.Save("bmp_24_new.bmp");

    return 0;
}