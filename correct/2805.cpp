// 나무 자르기
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, len, ans;
ll arr[1000001];

int main(int argc, char *argv[]){
    scanf("%lld %lld", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    
    sort(arr, arr+n);
    
    ll left = 1;
    ll right = arr[n-1];
    
    while(left <= right){
        ll mid = (left + right) / 2;
        
        for(int i=0; i<n; i++){
            if(arr[i] - mid > 0)
                len += arr[i] - mid;
        }
        
        if(len >= m){
            left = mid + 1;
            if(mid > ans)
                ans = mid;
        }
        else{
            right = mid -1;
        }
        
        len = 0;
    }
    
    cout << ans << "\n";
    return 0;
}
