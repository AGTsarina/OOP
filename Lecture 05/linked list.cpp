#include <string>

using namespace std;
// тип информационного поля - в дальнейшем параметр шаблона
struct Item{
    string name;
    int key;
    int * data;
};

// звено динамического списка
// (рекурсивная структура данных)
struct  Node
{
    Item info;
    Node *next;
    Node *prev;
};

class LinkedList{
    Node *first;
    Node *last;
public:
    // конструктор по умолчанию 
    LinkedList():first(nullptr), last(nullptr){}
    bool IsEmpty(){return !first;}
    void AddAfterLast(const Item &item){
        Node * node = new Node{item, nullptr, last};
        if (last)last->next = node;
        else{
            first = node;
        }
        last = node;
    }
};

