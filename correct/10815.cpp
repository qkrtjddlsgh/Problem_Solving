// 숫자 카드
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll a[500001];
ll b[500001];

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);
    
    scanf("%d", &m);
    
    for(int i=0; i<m; i++)
        scanf("%lld", &b[i]);
    
    sort(a, a+n);
    
    for(int i=0; i<m; i++){
        if(binary_search(a, a+n, b[i]) == 1)
            cout << "1 ";
        else
            cout << "0 ";
    }
    
    return 0;
}
