#include <iostream>
#include <functional>
#include <vector>
#include <string>
using namespace std;

class Button{
    public:
        function<void(string)> clicked;
};

class Window{
    vector<string> data;
    Button btnAdd;
    Button btnShow;
    Button btnDelete;
public:
    Window(){
        btnAdd.clicked = [this](string arg){this->data.push_back(arg);};
        btnShow.clicked = [this](string arg){
            for(string & line: data){
                cout << line << endl;
            }
            cout << endl;
        };
        btnDelete.clicked = [this](string arg){
            if (data.size())
                data.erase(data.begin());
        };
    }
    void addString(string line){
        btnAdd.clicked(line);
    }
    void showLines(){
        btnShow.clicked("");

    }
    void deleteString(){
        btnDelete.clicked("");
    }
    void changeOutputStyle(){
        btnShow.clicked = [this](string arg){
            cout << "This is the list of lines: \n";
            for(string & line: data){
                cout << line << endl;
            }
            cout << endl;
        };
    }
    void changeOutputStyle1(){
        btnShow.clicked = [this](string arg){
            
            for(string & line: data){
                cout <<"Line: " << line << endl;
            }
            cout << endl;
        };
    }
};
int main(){
    Window w;
    w.addString("First line");
    w.addString("New line");
    w.addString("Another line");
    w.showLines();
    w.deleteString();
    w.changeOutputStyle();
    w.showLines();
    w.changeOutputStyle1();
    w.showLines();
}

