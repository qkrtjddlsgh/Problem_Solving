// 연속합
#include <bits/stdc++.h>
using namespace std;

int n, arr[100001], res[100001];

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 1; i <= n; i++)
        res[i] = max(arr[i], res[i - 1] + arr[i]);
    
    int ans = res[1];
    
    for (int i = 2; i <= n; i++) {
        if (res[i] > ans)
            ans = res[i];
    }
    
    cout << ans << "\n";
    return 0;
}
