// 2xn 타일링 2
#include <bits/stdc++.h>
using namespace std;

long long dp[1001] = {0, 1, 3, };

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=3; i<=n; i++)
        dp[i] = ((2*dp[i-2]+dp[i-1]) % 10007);
    
    cout << dp[n] % 10007 << "\n";
    return 0;
}
