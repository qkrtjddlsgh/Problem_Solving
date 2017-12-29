#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int func(int cur){
    if(cur == 1) return 0;
    
    int &ret = dp[cur];
    if(ret != -1) return ret;
    
    ret = func(cur - 1) + 1;
    
    if(cur%3 == 0)
        ret = min(ret, func(cur / 3) + 1);
    if(cur%2 == 0)
        ret = min(ret, func(cur / 2) + 1);
    
    return ret;
}

int main(int argc, const char *argv[]) {
    int n;
    scanf("%d", &n);
    
    memset(&dp, -1, sizeof(dp));
    cout << func(n) << "\n";
    
    return 0;
}
