// 랜선 자르기
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, n, ans;
ll arr[10001];

int main(int argc, char *argv[]){
    scanf("%lld %lld", &k, &n);
    
    for(int i=0; i<k; i++)
        scanf("%lld", &arr[i]);
    
    sort(arr, arr+k);
    
    ll left = 1; // 런타임 에러
    ll right = arr[k-1];
    
    ll cnt = 0;
    
    while(left <= right){
        ll mid = (left + right) / 2;
        
        for(int i=0; i<k; i++){
            cnt += arr[i] / mid;
        }
        
        if(cnt >= n){
            left = mid + 1;
            
            if(mid > ans)
                ans = mid;
        }
        else{
            right = mid - 1;
        }
        
        cnt = 0;
    }
    
    cout << ans << "\n";
    return 0;
}
