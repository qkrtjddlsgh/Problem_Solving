#include <bits/stdc++.h>
using namespace std;

int input[1000][3];
int dp[1000][3];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            scanf("%d", &input[i][j]);
            dp[0][j] = input[0][j];
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            dp[i][0] = input[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = input[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = input[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
    }
    
    int result = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    cout << result << "\n";
    
    return 0;
}
