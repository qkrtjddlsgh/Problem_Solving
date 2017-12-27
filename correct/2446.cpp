// 별찍기 - 9
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int k=2; k<=i; k++){
            cout << " ";
        }
        for(int j=0; j<=2*n-2*i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    
    for(int i=2; i<=n-1; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int k=1; k<=2*i-1; k++){
            cout << "*";
        }
        cout << "\n";
    }
    
    if(n != 1){
        for(int i=0; i<2*n-1; i++)
            cout << "*";
        cout << "\n";
    }
    
    return 0;
}
