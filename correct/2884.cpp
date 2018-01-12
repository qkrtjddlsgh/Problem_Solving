// 알람 시계
#include <bits/stdc++.h>
using namespace std;

int h, m;

int main(int argc, char *argv[]){
    scanf("%d %d", &h, &m);
    
    if(m > 45){
        cout << h << " " << m-45 << "\n";
    }
    else{
        m = m-45+60;
        
        if(h > 1)
            h -= 1;
        else
            h += 23;
        
        cout << h << " " << m << "\n";
    }
    
    return 0;
}
