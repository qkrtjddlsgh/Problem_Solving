// RGB거리
#include <bits/stdc++.h>
using namespace std;

int n, maxval;
int arr[1001][3];
int dp[1001][3];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
            dp[0][j] = arr[0][j];
        }
    }
    
    for(int i=1; i<n; i++){
        dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    
    maxval = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    cout << maxval << "\n";
    
    return 0;
}
