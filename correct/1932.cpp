// 숫자삼각형
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
            dp[0][j] = arr[0][j];
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            dp[i][j] = max(arr[i][j] + dp[i-1][j], arr[i][j] + dp[i-1][j-1]);
        }
    }
    
    int maxval = 0;
    
    for(int i=0; i<n; i++){
        maxval = max(maxval, dp[n-1][i]);
    }
    
    cout << maxval << "\n";
    return 0;
}
