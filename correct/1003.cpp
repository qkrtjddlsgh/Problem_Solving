#include <bits/stdc++.h>
using namespace std;

int ans[2];

int fibo(int n){
    if(n==0){
        ans[0]++;
        return 0;
    }
    if(n==1){
        ans[1]++;
        return 1;
    }
    
    return fibo(n-1) + fibo(n-2);
}

int main(int argc, const char * argv[]) {
    int tc;
    scanf("%d", &tc);
    
    while(tc--){
        int n;
        scanf("%d", &n);
        
        fibo(n);
        cout << ans[0] << " " << ans[1] << "\n";
        memset(ans, 0, sizeof(ans));
    }
    
    return 0;
}
