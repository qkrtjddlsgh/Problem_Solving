#include <bits/stdc++.h>
using namespace std;

long long dp[1001];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    
    // 3 5 7 9
    // 4 6 8 10
    
    for(int i=5; i<=n; i++){
        dp[i] = dp[i-1] % 10007 + dp[i-2] % 10007;
    }
    
    cout << dp[n] % 10007 << "\n";
    return 0;
}
