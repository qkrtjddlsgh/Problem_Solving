// 수들의 합
#include <bits/stdc++.h>
using namespace std;

long long sum, ans;

int main(int argc, char *argv[]){
    long long n;
    scanf("%lld", &n);
    
    for(long long i=1; i<=4294967295; i++){
        sum += i;
        
        if(sum == n){
            ans = i;
            break;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
