// 네번째 점
#include <bits/stdc++.h>
using namespace std;

int x, y, x4, y4;

int main(int argc, char *argv[]){
    
    for(int i=0; i<3; i++){
        scanf("%d %d", &x, &y);
        x4 ^= x; y4 ^= y;
    }
    
    cout << x4 << " " << y4 << "\n";
    return 0;
}
