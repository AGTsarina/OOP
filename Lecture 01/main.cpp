#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Item{ // объявление пользовательского типа данных
    // свойства объекта = поля класса
private: // модификатор, полностью закрывающий поля и методы от внешнего доступа
    int key;
    string name;
    double param;
protected: // модификатор, предоставляющий доступ только внутри иерархии наследования
public: // открытый доступ
    // действия, которые умеет совершать объект = методы класса
    // конструктор
    // 1. Порторяет имя класса
    // 2. Не имеет возвращаемого результата
    // 3. Может иметь любой набор параметров
    // 4. Констуктор может быть перегружен
    Item(int key, string name, double param){
        this->key = key;     // (*this).key
        this->name = name;
        this->param = param;
    }
    // Конструктор по умолчанию
    Item(){
        this->key = 0;
        this->name = "<undefined>";
        this->param = 0.0;
    }

    // вывод информации об объекте
    void print(ostream & output){
        output << key << " " << name << " " << param << endl;
    }
    int compare(Item & item){
        // скрытый параметр - указатель(!!!) на текущий объект this 
        if (param < item.param)
        return -1;
        if (abs(param - item.param) < 1e-7)
        return 0;
        return 1;
    }
};

int main(){
    int x(7);
    Item item(1, "first", 3.5);
    string s("first"), s1("____________________________________second__________________________________________________________");

    cout << sizeof(string) <<" " << sizeof(s) << " " << sizeof(s1)<<endl;
    cout << sizeof(Item) << " " << sizeof(item) << endl;
    Item another_item(2, "second", -4.7);
    Item zero; // работает конструктор по умолчанию
    item.print(cout);
    another_item.print(cout);
    auto res = item.compare(another_item);
    return 0;
}