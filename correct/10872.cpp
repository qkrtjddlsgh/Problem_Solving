// 팩토리얼
#include <bits/stdc++.h>
using namespace std;

int ans = 1;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    if(n==0){
        cout << "1\n";
        return 0;
    }
    
    for(int i=1; i<=n; i++)
        ans *= i;
    
    cout << ans << "\n";
    return 0;
}
