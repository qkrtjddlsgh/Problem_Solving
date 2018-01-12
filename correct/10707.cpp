// 수도요금
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, p, x, y;

int main(int argc, char *argv[]){
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &p);
    
    x = a * p;
    
    if(p < c)
        y = b;
    else
        y = b + d * (p-c);
    
    if(x < y)
        cout << x << "\n";
    else
        cout << y << "\n";
    
    return 0;
}
