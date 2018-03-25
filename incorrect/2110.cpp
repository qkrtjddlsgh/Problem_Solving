// 공유기 설치
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, c, cnt, cur, ans;
ll arr[200001];

int main(int argc, char *argv[]){
    scanf("%lld %lld", &n, &c);
    
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    
    // 1 2 4 8 9
    sort(arr, arr+n);
    
    ll left = 1;
    ll right = arr[n-1] - arr[0];
    
    // 조건1. 최대로 많은 곳에서 와이파이 사용
    // 조건2. 가장 인접한 두 공유기 사이의 거리가 최대인 경우
    
    while(left <= right){
        ll mid = (left + right) / 2; // 간격
        
        cnt = 1; // 첫 번째집에 무조건 설치
        cur = arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i] - cur >= mid){
                cnt++;
                cur = arr[i];
            }
        }
        
        // c == 3
        if(cnt >= c){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
