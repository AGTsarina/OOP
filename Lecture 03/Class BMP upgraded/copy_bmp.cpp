#include <fstream>
#include <iostream>

#include "bmp.h"

using std::fstream, std::ifstream, std::ofstream, std::ios;
using std::cout;



int main(){ 
    fstream fmaze("maze.bmp", ios::binary|ios::in|ios::out);   
    fstream fsnail("snail.bmp", ios::binary|ios::in|ios::out);
    BMP maze(fmaze);
    BMP snail(fsnail);
    // замена цвета
    maze.Copy(snail);
    maze.Save("res.bmp");

    return 0;
}