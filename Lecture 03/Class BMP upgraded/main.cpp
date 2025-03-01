#include <fstream>
#include <iostream>

#include "bmp.h"

using std::fstream, std::ifstream, std::ofstream, std::ios;
using std::cout;



int main(){    
    fstream bmp_file("snail.bmp", ios::binary|ios::in|ios::out);
    BMP bmp(bmp_file);
    // замена цвета
    bmp.ReplaceColor(Color{0,0,255}, Color{0,0,255});
    bmp.ReplaceColor(Color{255,0,0}, Color{255,0,0});
    bmp.ReplaceColor(Color{0,255,0}, Color{0,255,0});
    // нарисовать прямоугольник color цвета
    //bmp.FillRect(Rect{10, 10, 50, 20}, Color{255,255,255});
    bmp.Save("res.bmp");

    return 0;
}