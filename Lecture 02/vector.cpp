#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Vector{
    int _size;
    int _capacity;
    int *_data; // динамическое поле

public:
    // конструктор
    Vector(){
        _size = 0;
        _capacity = 100;
        _data = new int [_capacity]; // выделение памяти под динамич. поле
    }
    // деструктор
    ~Vector(){
        // удаление динамических полей
        if (_data) delete[] _data;
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
    // При наличии динамических полей должна быть предусмотрена 
    // система копирования объектов так, чтобы они НЕ разделяли
    // общие ресурсы
    // 1. должен быть перегружен оператор копирования (присваивания)    
    Vector& operator = (const Vector &v){
        _size = v._size;
        _capacity = v._capacity;
        // удаляем "старый" массив
        if (_data) delete[] _data;
        // создаем новый массив данных
        _data = new int[_capacity];
        // копируем данные
        for(int i=0; i<_size; i++){
            _data[i] = v._data[i];
        }
        // возвращаем в качестве результата текущий объект
        return *this;
    }

    // 2. должен быть написан(перегружен) конструктор копирования
    Vector(const Vector &v){
        _size = v._size;
        _capacity = v._capacity;        
        // создаем новый массив данных
        _data = new int[_capacity];
        // копируем данные
        for(int i=0; i<_size; i++){
            _data[i] = v._data[i];
        }
    }
};

int main(){
    /*vector<int> v; // обобщенный класс, то есть тип элементов является параметром
    // типа массива (обобщенный тип (С++) = шаблон класса)
    */
    int a, b, c;
    a = b = c = 0;
    Vector v;

    cout << v.capacity()<<" "<< v.size() <<endl;
    v.push_back(5);
    v.push_back(7);
    v.push_back(1);
    
    Vector v1 = v; // конструктор копирирования
    Vector v2(v);  // конструктор копирирования
    v2 = v1 = v; // оператор присваивания
    v.push_back(10);
    return 0;  

}

//tsarinaAG@yandex.ru