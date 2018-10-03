// 시험감독 : 단순 계산
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, arr[1000001], b, c, ans; // int 범위 조심 (20억 이상이면 long long)

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    cin >> b >> c;
    
    for(int i=0; i<n; i++){
        arr[i] -= b;
        ans += 1;
        
        if(arr[i] <= 0)
            continue;
        else{
            if(arr[i] % c == 0){
                ans += arr[i] / c;
            }
            else{
                ans += arr[i] / c + 1;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
