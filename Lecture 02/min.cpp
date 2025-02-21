#include <iostream>
#include <string>
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
    // внутреннее переопределение оператора сравнения (меньше)
    bool operator < (const Item & item) const{ //    (*this) < item
        return param < item.param;
    }
    // объявление, что внешний опрератор вывода в поток 
    // будет дружественным, то есть ему доверяем
    // доступ к скрытым полям 
    friend ostream & operator << (ostream & output, Item &item);
};

// внешнее переопределение оператора вывода в поток
ostream & operator << (ostream & output, Item &item){
    output << item.key << " " << item.name << " " << item.param;
    return output;
}


int main(){
    int a = 6, b = 10;
    cout << a << endl;
    int c = min(a, b);
    Item A(1, "A", 10), B(5, "object", 7.5);   

    //auto C = A < B? A : B;
    auto C = min(A, B);

    A.print(cout);
    cout << A << " " << B << endl;

    return 0;
}