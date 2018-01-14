// 완전제곱수
#include <bits/stdc++.h>
using namespace std;

int m, n, sum, minval = 987654321;

int main(int argc, char *argv[]){
    scanf("%d %d", &m, &n);
    
    for(int i=1; i<=100; i++){
        if(i*i <= n && i*i >= m){
            minval = min(i, minval);
            sum += i*i;
        }
    }
    
    if(!sum){
        cout << "-1\n";
        return 0;
    }
    
    cout << sum << "\n" << minval * minval << "\n";
    return 0;
}
