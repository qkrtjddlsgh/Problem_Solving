// 지능형 기차
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main(int argc, char *argv[]){
    for(int i=0; i<4; i++){
        scanf("%d %d", &a, &b);
        
        if(i==0){
            c = b;
            d = c;
        }
        else{
            c = c - a + b;
            if(c > d)
                d = c;
        }
    }
    
    cout << d << "\n";
    return 0;
}
