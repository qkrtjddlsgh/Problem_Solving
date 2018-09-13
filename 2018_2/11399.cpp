#include <iostream>
#include <algorithm>
using namespace std;

int n, cur, ans, arr[1001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    
    for(int i=0; i<n; i++){
        cur += arr[i];
        ans += cur;
    }
    
    cout << ans << "\n";
    return 0;
}
