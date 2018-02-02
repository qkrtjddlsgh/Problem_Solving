// 피보나치 함수
#include <bits/stdc++.h>
using namespace std;

int tc, n, z_cnt, o_cnt;

int fibo(int n){
    if(n == 0){
        z_cnt++;
        return 0;
    }
    if(n == 1){
        o_cnt++;
        return 0;
    }
    else
        return fibo(n-1) + fibo(n-2);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    while(tc--){
        cin >> n;
        fibo(n);
        
        cout << z_cnt << " " << o_cnt << "\n";
        z_cnt = o_cnt = 0;
    }
    
    return 0;
}
