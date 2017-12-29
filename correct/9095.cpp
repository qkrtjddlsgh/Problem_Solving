// 1,2,3 더하기
#include <bits/stdc++.h>
using namespace std;

int dp[11] = {0, 1, 2, 4,};

int main(int argc, char *argv[]){
    int tc, n;
    scanf("%d", &tc);
    
    while(tc--){
        scanf("%d", &n);
        
        for(int i=4; i<=n; i++)
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        
        cout << dp[n] << "\n";
    }
    
    return 0;
}
