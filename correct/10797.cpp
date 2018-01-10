// 10부제
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n, temp, ans = 0;
    scanf("%d", &n);
    
    for(int i=0; i<5; i++){
        scanf("%d", &temp);
        
        if(temp == n)
            ans++;
    }
    
    printf("%d\n", ans);
    return 0;
}
