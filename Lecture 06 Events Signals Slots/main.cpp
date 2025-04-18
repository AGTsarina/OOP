#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
using namespace std;

//typedef double (*oneParamFunction)(double);
//typedef double (*fourParamFunction)(double, double, double, double);

using oneParamFunction = function<double(double)>;
using fourParamFunction = function<double(double, double, double, double)>;

double f1(double x){
    return sin(x)+ cos(2 * x);
}

double f2(double x){
    return x * x * x - 5 * x * x + 10;
}

double f3(double x, double a, double b, double c){
    return a *x * x * x - b * x * x + c;
}

double f4(double x, double a, double b, double c){
    return a *sin(x)+ b *cos(c * x);
}

void print(oneParamFunction f){
    for(double x = 0; x < 1; x+=0.1){
        cout << x << " " << f(x) << endl;
    }
    cout << endl;
}

void print(fourParamFunction f, double a, double b, double c){
    for(double x = 0; x < 1; x+=0.1){
        cout << x << " " << f(x, a, b, c) << endl;
    }
    cout << endl;
}


int main(){
    // typedef double (*oneParamFunction)(double);
    
    vector<oneParamFunction> functions;
    functions.push_back(f1);
    functions.push_back(f2);
    oneParamFunction f_lambda = [](double x){return x*x;};
    functions.push_back(f_lambda);
    functions.push_back([](double x){return exp(-x);});
    double a = 1, b = 1, c = 1;
    functions.push_back([=](double x){return f3(x, a, b, c);});
    functions.push_back([&a, &b, &c](double x){       
        return f3(x, a, b, c);
    });

    for(auto &f: functions){ 
        print(f);
    }
    
    print(f3, 1,1,1);
    print(f4, 1,1,1);
}