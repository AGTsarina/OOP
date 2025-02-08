#include <iostream>
using namespace std;

class Car{
    double x, v, a;
    int direction;
public:
    Car(double x, double v, double a, int direction);
    void move(double dt);
    bool meet(const Car &car) const;    
};

int main(){
    double S = 1000;
    double t = 0, dt = 0.00001;
    Car car1(0, 60, 0.5, 1);
    Car car2(S, 70, 0.1, -1);
    for(; !car1.meet(car2); t += dt){
        car1.move(dt);
        car2.move(dt);
    }
    cout << "Время встречи: " << t << endl;
}
// Оператор :: доступ к элементам (полям и методам) класса через имя класса
// Оператор . доступ к элементам (полям и методам) класса через объект класса
// Оператор -> доступ к элементам (полям и методам) класса через указатель на объект класса

Car::Car(double x, double v, double a, int direction){
    this->a = a;
    this->v = v;
    this->direction = direction;
    this->x = x;
}
void Car::move(double dt){
    this->v += direction * a * dt;
    this->x += direction * v * dt;
}
bool Car::meet(const Car &car) const{
    if (this->x > car.x) return true;
    return false;
} 

