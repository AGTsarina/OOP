#include <iostream>
using namespace std;

void f(){
    int x = 10;
    static int X = 10;
    cout << x++ << " " << X++ << endl;
}
unsigned long fib(unsigned long n){
    static unsigned int count = 0;
    cout << ++count << "\n";
    if (n < 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    fib(10);
}