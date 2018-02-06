// 연속합
#include <bits/stdc++.h>
using namespace std;

int n, maxval, arr[100001], dp[100001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    dp[0] = arr[0];
    
    for(int i=0; i<n; i++){
        dp[i] = max(arr[i], arr[i] + dp[i-1]);
        maxval = max(dp[i], maxval);
    }
    
    cout << maxval << "\n";
    
    return 0;
}
