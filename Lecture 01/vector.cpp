#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Vector{
    int _size;
    int _capacity;
    int *_data;

public:
    Vector(){
        _size = 0;
        _capacity = 100;
        _data = new int [_capacity];
    }
    int size(){ return _size;}
    int capacity(){return _capacity;}
    void push_back(int value){
        if (_size == _capacity) return;
        _data[_size] = value;
        _size++;
    }
    int* data(){return _data;}
    void print(){
        for(int i=0; i< _size; i++){
            cout << _data[i]<< " ";
        }
        cout << endl;    
    }
};

int main(){
    /*vector<int> v; // обобщенный класс, то есть тип элементов является параметром
    // типа массива (обобщенный тип (С++) = шаблон класса)
    */
    Vector v;
    cout << v.capacity()<<" "<< v.size() <<endl;
    v.push_back(5);
    v.push_back(7);
    v.push_back(1);
    v.print();
    int * data = v.data();
    data[0] = 10;
    v.print();
    cout << v.capacity()<<" "<< v.size() <<endl;
    cout << sizeof(v) <<endl;

}