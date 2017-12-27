// 별찍기 - 8
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        for(int k=2*n-1-2*i; k>=0; k--){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=n-i; j++){
            cout << "*";
        }
        for(int k=1; k<=2*i; k++){
            cout << " ";
        }
        for(int j=1; j<=n-i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
