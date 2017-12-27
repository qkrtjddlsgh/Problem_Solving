// 랜선 자르기
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, n, cnt;
ll arr[10001];
ll ans;

int main(int argc, char *argv[]){
    scanf("%d %d", &k, &n);
    
    ll left = 1;
    ll right = -1;
    
    for(int i=0; i<k; i++){
        scanf("%lld", &arr[i]);
        
        if(arr[i] > right)
            right = arr[i];
    }
    
    while(left <= right){
        long long len = (left + right) / 2;
        
        for(int i=0; i<k; i++)
            cnt += arr[i]/len;
        
        if(cnt >= n){
            left = len + 1;
            if(len > ans)
                ans = len;
        }
        else
            right = len - 1;
        
        cnt = 0;
    }
    
    cout << ans << "\n";
    return 0;
}
