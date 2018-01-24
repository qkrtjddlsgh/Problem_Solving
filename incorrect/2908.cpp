// 상수
#include <bits/stdc++.h>
using namespace std;

string a, b;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> a >> b;
    
    reverse(&a[0], &a[3]);
    reverse(&b[0], &b[3]);
    
    if(a > b){
        cout << a << "\n";
    }
    else
        cout << b << "\n";
    
    return 0;
}
