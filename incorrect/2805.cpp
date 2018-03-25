// 나무 자르기
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, ans;
ll arr[1000001];

int main(int argc, char *argv[]){
    scanf("%lld %lld", &n, &m);
    
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    
    sort(arr, arr+n);
    
    ll left = 0;
    ll right = arr[n-1];
    
    ll sum = 0;
    
    while(left <= right){
        ll mid = (left + right) / 2;
        
        for(int i=0; i<n; i++){
            if(arr[i] - mid > 0)
                sum += arr[i] - mid;
        }
        
        if(sum >= m){
            left = mid + 1;
            
            if(mid > ans)
                ans = mid;
        }
        else{
            right = mid - 1;
        }
        
        sum = 0;
    }
    
    cout << ans << "\n";
    return 0;
}
