// 파스칼
#include <bits/stdc++.h>
using namespace std;

int n, counter;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=n-1; i>=1; i--){
        counter += 1;
        
        if(n%i == 0)
            break;
    }
    
    cout << counter << "\n";
    return 0;
}
