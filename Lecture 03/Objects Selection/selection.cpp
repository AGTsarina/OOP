#include <vector>
#include <string>

using std::vector, std::string;


struct Item
{
    int key;
    string info;
};

typedef bool (*Property)(const Item& n);
typedef void (*Action)(Item& n);

struct Vector{
    vector<Item> data;
    vector<Item *> selected;
    Vector():data({
        {1, "item 1"},
        {2, "item 2"},
        {3, "item 3"},
        {4, "item 4"},
        {5, "item 5"}}), selected(){}
    void Select(Property p){
        selected.clear();
        for(auto& item: data){
            if (p(item)){
                selected.push_back(&item);
            }
        }
    }
    void ChangeSelected(Action a){
        for(Item * pItem: selected){
            a(*pItem);
        }
    }

};

bool Even(const Item&item){
    return !(item.key % 2);
}

void Add1(Item&item){
    item.key++;
}


int main(){
    Vector v;
    v.Select(Even);
    v.ChangeSelected(Add1);
    return 0;
}