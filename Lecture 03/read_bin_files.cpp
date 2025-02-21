#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream input("data.txt", ios::binary);
    // переводим "маркер" в конец файла
    input.seekg(0, ios::end);
    int file_size = input.tellg();
    int size = file_size / sizeof(short);
    short *x = new short[size]; 
    input.clear();
    input.seekg(0, ios::beg);
    input.read((char *)x, sizeof(short) * size);
    return 0;

}