// 상근날드
#include <bits/stdc++.h>
using namespace std;

int a[5];

int main(int argc, char *argv[]){
    
    for(int i=0; i<3; i++)
        scanf("%d", &a[i]);
    
    sort(a, a+5);
    
    scanf("%d %d", &a[3], &a[4]);
    
    if(a[3] > a[4])
        cout << a[2] + a[4] - 50 << "\n";
    else if(a[3] < a[4])
        cout << a[2] + a[3] - 50 << "\n";
    else
        cout << a[2] + a[3] - 50 << "\n";
    
    return 0;
}
