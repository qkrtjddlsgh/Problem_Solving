// X와 K
#include <bits/stdc++.h>
using namespace std;

long long X, K, Y, cnt;
int i=1;

int main(int argc, char *argv[]){
    scanf("%lld %lld", &X, &K);
    
    while(1){
        if((X + i) == (X | i)){
            cnt++;
            Y = i;
            
            if(cnt == K)
                break;
        }
        i++;
    }
    
    printf("%lld\n", Y);
    return 0;
}
