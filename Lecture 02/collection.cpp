// работа с массивом (коллекцией) объектов
#include <vector>
#include <fstream>
#include "item.h"

int main(){
    ifstream input("data.txt");
    int n;
    input >> n;
    vector<Item> v(n);
    for (int i=0; i<n; i++){
        Item item;
        input >> item;
        v[i] = item;
    }


    Item item1(1, "A", 1.0);
    v.push_back(item1);
    Item item2(2, "B", 2.0);
    v.push_back(item2);
    for(auto item: v){
        cout << item << endl;
    }
    
}