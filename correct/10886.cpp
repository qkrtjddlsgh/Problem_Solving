// 0 = not cute / 1 = cute
#include <bits/stdc++.h>
using namespace std;

int n, temp, cnt1, cnt2;

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        
        if(temp == 1)
            cnt1++;
        else
            cnt2++;
    }
    
    if(cnt1 < cnt2)
        cout << "Junhee is not cute!\n";
    else
        cout << "Junhee is cute!\n";
    
    return 0;
}
