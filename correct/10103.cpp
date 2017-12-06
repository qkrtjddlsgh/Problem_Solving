// 주사위 게임
#include <bits/stdc++.h>
using namespace std;

int a = 100, b = 100;

int main(int argc, char *argv[]){
    int tc;
    scanf("%d", &tc);
    
    while(tc--){
        int x, y;
        scanf("%d %d", &x, &y);
        
        if(x>y) b -= x;
        else if(x<y) a -= y;
        else continue;
    }
    
    printf("%d\n%d\n", a, b);
    return 0;
}
