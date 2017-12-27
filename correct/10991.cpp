// 별 찍기 - 16
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int k=1; k<=2*i-1; k++){
            if(k%2 == 0)
                cout << " ";
            else if(k%2 == 1)
                cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
