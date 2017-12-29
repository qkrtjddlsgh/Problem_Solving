// 피보나치 수 2
#include <bits/stdc++.h>
using namespace std;

long long fibo[91] = {0, 1, };

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=2; i<=n; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
    
    cout << fibo[n] << "\n";
    return 0;
}
