// 막대기
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n, ans = 0, len = 64;
    scanf("%d", &n);
    
    while(n > 0){
        if(len > n)
            len /= 2;
        else{
            ans++;
            n -= len;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
