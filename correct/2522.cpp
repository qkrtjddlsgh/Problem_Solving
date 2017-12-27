// 별찍기 - 12
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n-i; k++){
            cout << " ";
        }
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=i; j++){
            cout << " ";
        }
        for(int k=1; k<=n-i; k++){
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
