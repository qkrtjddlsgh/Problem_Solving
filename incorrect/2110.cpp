// 공유기 설치
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, c;
ll home[200001];

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &c);
    
    for(int i=0; i<n; i++)
        scanf("%lld", &home[i]);
    
    sort(home, home+n);
    
    ll left = 1;
    ll right = home[n-1] - home[0];
    
    while(left <= right){
        
    }
    
    return 0;
}
