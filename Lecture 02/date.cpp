#include <vector>
#include <iostream>
using namespace std;
const int days[12]{31,28,31, 0,0,0,0,0,0,0,0,0};
class Date{
    
    int day, month, year;
    public:
    static int shared;
    static int days[12];
    Date(int d=0, int m=0, int y=0):day(d), month(m), year(y){
        cout << "Работает конструктор с параметрами\n";  
        shared++;  
        cout << days[0]<< endl;    
    }
    Date(const Date &date):day(date.day), month(date.month),
    year(date.year){
        cout << "Работает конструктор копирования\n";
        shared++; 
    }

    Date(Date &&date):day(date.day), month(date.month),
    year(date.year){
        cout << "Работает конструктор копирования!!!\n";
        shared++; 
    }
    /*Date():day(0), month(0),year(0){
        cout << "Работает конструктор по умолчанию\n";
    }*/
    ~Date(){
        shared--;
        cout << "Работает деструктор\n";
    }
};

int Date::shared = 0;
int Date::days[12]{31,28,31};

class List{
    vector<Date> v;
    public:
    void Task1(){}
    void Task2(){}
    // ...
    void TaskN(){}
};

int Menu(){return 0;}
/*int main(){
    cout << "Size of Date: " << sizeof(Date) << endl;
    List data;
    int choice;
    do
    {
      choice =  Menu();
      switch (choice)
      {
      case 1:
        data.Task1();
        break;
      case 2:
        data.Task2();
        break;
      default:
        break;
      }
    } while(choice);
}*/


 // Создание пустого массива с заданной емкостью
int main(){
    cout << "Size of Date: " << sizeof(Date) << endl;
    int n = 5;    
    vector<Date> v;
    
    v.reserve(n); // Меняем есмкость массива
    cout << "Размер: " << v.size() << " " << "Объем: " << v.capacity() << "\n";
    int d, m, y;
    for(int i=0; i< n; i++){
        cout << "Введите дату:\n";
        //cin >> d >> m >> y;
        
        v.push_back(Date());
        cout << "Размер: " << v.size() << " " << "Объем: " << v.capacity() << "\n";
    }
    cout << "Shared: ";
    cout << Date::shared<< endl;
    cout << v[0].shared << " " << v[4].shared << endl;
    return 0;
}

/* // создание изначально пустого массива(вектора)
int main(){
    int n = 5;    
    vector<Date> v;
    int d, m, y;
    for(int i=0; i< n; i++){
        cout << "Введите дату:\n";
        cin >> d >> m >> y;
        v.push_back(Date(d, m, y));
        cout << "Размер: " << v.size() << " " << "Объем: " << v.capacity() << "\n";
    }
    return 0;
}
*/

/* // создание массива(вектора) из заданного количества элементов
int main(){
    int n = 5;
    // vector<int> vi(n);
    vector<Date> v(n);
    int d, m, y;
    for(int i=0; i< n; i++){
        cout << "Введите дату:\n";
        cin >> d >> m >> y;
        v[i] = Date(d, m, y);
        cout << "Размер: " << v.size() << " " << "Объем: " << v.capacity() << "\n";
    }
    return 0;
}
*/