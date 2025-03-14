// Наследование
// Построение иерархии классов
// Базовый класс - класс, который находится в вершине иерархического дерева (поддерева)
// и поставлет харектеристике и систему поведения для своих наследников
// Производный класс - класс-наследник, который либо детализирует базовый класс, либо
// расширяет его функциональность

// Построение иерархии наследования
#include <vector>
#include <iostream>
using namespace std;
// Базовый класс
class Figure{
protected:
    double x0, y0;
public:
    Figure(double x0=0, double y0=0):x0(x0), y0(y0){  
        cout << "Figure constructed\n";      
    }
    void print(){cout << "Figure in point " << x0 << " " << y0 << "\n";}
    bool contains(Figure& f){return false;}
    ~Figure(){
        cout << "Figure distructed\n";
    }
};

class Point: public Figure{
public:
    Point(){
        cout << "Point constructed\n";
        cout << x0 << " " << y0 << "\n"; 
    }
    ~Point(){
        cout << "Point distructed\n";
    }
};

// производный класс многоугольник
class Polygon: public Figure{
    vector<Point> points;
    public:
    Polygon(){}
};

class Circle: public Figure{
    double R;
public:
    Circle(){}
};

class Triangle:public Polygon{
    public:
    Triangle(){}
};

int main(){
    Polygon poly;
    poly.print();
    Triangle tr;
    Point point;
    
    point.print();
    Circle circle;
    return 0;
}

