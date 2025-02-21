#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
class Text{
    vector <string> text;
public:
    Text(string filename);
    int length(){return text.size();}
    int emptyLines(){
        int res = 0;
        for(auto line: text){
            if (line.length() == 0)
                res++;
        }
        return res;
    }
};

int main(){
    Text text("text.txt");  
    cout << text.length() << endl; 
    cout << text.emptyLines() << endl; 
    return 0;
}

Text::Text(string filename){
    ifstream input(filename);
    for(;!input.eof();){
        string s;
        getline(input, s);
        text.push_back(s);
    }
}

