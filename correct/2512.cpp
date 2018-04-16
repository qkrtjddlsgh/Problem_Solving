// 예산
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, sum, arr[10001];
ll m, ans;

int main(int argc, char *argv[]){
    scanf("%lld", &n);
    
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    
    scanf("%lld", &m);
    sort(arr, arr+n);
    
    ll left = 0;
    ll right = arr[n-1];
    
    if(sum <= m){
        cout << arr[n-1] << "\n";
        return 0;
    }
    else{
        while(left <= right){
            ll mid = (left + right) / 2;
            sum = 0;
            
            for(int i=0; i<n; i++){
                if(mid - arr[i] >= 0)
                    sum += arr[i];
                else
                    sum += mid;
            }
            
            if(sum <= m){
                left = mid + 1;
                
                if(mid > ans)
                    ans = mid;
            }
            else{
                right = mid - 1;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
