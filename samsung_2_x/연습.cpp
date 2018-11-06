// 연습
#include <iostream>
using namespace std;

int arr[21];

void func(int cur){
    if(cur == 5){
        for(int i=0; i<5; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    
    for(int i=0; i<2; i++){
        arr[cur] = i;
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    func(0);
    
    return 0;
}
