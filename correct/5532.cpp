// 방학 숙제
#include <bits/stdc++.h>
using namespace std;

int l, a, b, c, d;

int main(int argc, char *argv[]){
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    
    int math =  a / c;
    int korean = b / d;
    
    if(math > korean){
        if(a%c == 0)
            cout << l - math << "\n";
        else
            cout << l - (math + 1) << "\n";
    }
    else{
        if(b%d == 0)
            cout << l - korean << "\n";
        else
            cout << l - (korean + 1) << "\n";
    }
    
    return 0;
}
