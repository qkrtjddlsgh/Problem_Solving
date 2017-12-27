// 별 찍기 - 17
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    if(n==1){
        cout << "*\n";
        return 0;
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int k=1; k<=2*i-1; k++){
            if(k==1 || k==2*i-1){
                cout << "*";
                continue;
            }
            else{
                cout << " ";
                continue;
            }
        }
        cout << "\n";
    }
    
    for(int i=1; i<=2*n-1; i++)
        cout << "*";
    
    cout << "\n";
    return 0;
}
