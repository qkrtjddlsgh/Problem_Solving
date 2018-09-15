#include <iostream>
using namespace std;

int a, b;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> a >> b;
    
    if(a > b){
        cout << ">\n";
    }
    else if(a == b){
        cout << "==\n";
    }
    else{
        cout << "<\n";
    }
    
    return 0;
}
