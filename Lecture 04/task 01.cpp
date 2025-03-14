// Задача: Дан набор фигур на плоскости
// (точки, окружности, многоугольники, треугольники, прямоугольники и т.д)
// Для каждой фигуры определить, сколько других фигур она содержит

// Построение иерархии наследования
#include <vector>
#include <iostream>
using namespace std;
// Базовый класс
class Figure{
protected:
    double x0, y0;
public:
    Figure(double x0=0, double y0=0):x0(x0), y0(y0){  }
    /*Виртуальный метод в C++ — это метод, который может быть переопределён
    в классах-наследниках так, что конкретная реализация метода для вызова будет
    определяться во время исполнения. */
    /*Чисто виртуальный метод в C++ — это метод, тело которого не определено.
    После объявления виртуального метода в нём пишут «= 0».*/
    virtual void print()=0;
    virtual bool contains(Figure& f)=0;

    virtual ~Figure(){}
    double X0() const{return x0;}
    double Y0() const{return y0;}
};

class Point: public Figure{
public:
    Point(double x0=0, double y0=0):Figure(x0, y0){ }
    ~Point(){ }
    void print() override {cout << "Point " << x0 << " " << y0 << "\n";}
    bool contains(Figure& f) override{       
        return false;
    }
};

// Вектор включает точку, не участвует в иерархии наследования
class Vector{
    Point A, B;
    double dx, dy;
public:
    Vector(const Point &A, const Point &B):A(A),B(B){
        dx = B.X0() - A.X0();
        dy = B.Y0() - A.Y0();
    }
    int sign_vector_product(Vector & v){
        return this->dx * v.dy - v.dx * this-> dy;
    }
};

// производный класс многоугольник
class Polygon: public Figure{
    vector<Point> points;
    public:
    Polygon(vector<Point> points):Figure(), points(points){        
    }
    void print() override {
        cout << "Polygon:\n";
        for(Point &p: points){
            p.print();
        }
        cout << "\n";
    }
    bool contains(Figure&p){
        // перебираем все точки многоугольника
        Point& point = (Point&)p;
        for(int i=0; i<points.size(); i++){
            Point& A = points[i];
            Point& B = points[(i+1)% points.size()];
            Vector v(A, B);
            Vector v0(B, point);
            int pr = v.sign_vector_product(v0);
            cout << "pr = " << pr << "\n";
        }
        return true;
    }
};


int main(){
    vector<Point> points({Point(0,0), Point(2,1), Point(4,0)});
    Polygon poly(points);
    
    poly.print();    
    Point pointA(1,1);   // !!! Должно быть (2, 0.5) 
    poly.contains(pointA);   
    pointA.print();  
    Point pointB(10, 4); 
    pointA.contains(pointB);
    pointA.contains(poly);
    /*   
    pointB.print(); 
    vector<Figure*> pointers({&pointA, &pointB, &poly});
    for(auto p: pointers){
        p->print();
    }   */
    return 0;
}

