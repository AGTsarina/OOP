#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int x[]{1,2,3,4,5,6,7,8,9,10};
    int y = 10;
    int *px = x;
    char *b = (char *)px;
    for(int i=0;i<40; i++){
        cout << hex<< (int)b[i] <<" ";
    }
    cout << endl;
    ofstream output("data.txt", ios::binary);
    output.write(b, sizeof(int) * 10);

}