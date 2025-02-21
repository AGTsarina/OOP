#include <iostream>
#include <fstream>
using namespace std;
struct Color
{
    unsigned char b,g,r;
};

int main(){
    fstream file("bmp_24.bmp", ios::binary|ios::out|ios::in);
    // переводим "маркер" в конец файла
    // input.seekg(0, ios::end);
    // int file_size = input.tellg();
    // int size = file_size / sizeof(short);
    
    file.seekg(54 + 3, ios::beg);    
    Color color;
    cout << "Size of color " << sizeof(color)<< endl;
    file.read((char *)&color, 3);
    // input.read((char *)&color.b, 1);
    // input.read((char *)&color.g, 1);
    // input.read((char *)&color.r, 1);
    cout << "Color R " << (int)color.r << endl;
    cout << "Color G " << (int)color.g << endl;
    cout << "Color B " << (int)color.b << endl;

    file.seekp(54 + 3, ios::beg);
    Color red{0,0,255};
    file.write((char *)&red, 3);
    return 0;

}