// 설탕배달
#include <bits/stdc++.h>
using namespace std;

int ans = 987654321, minval;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    int maxval = n / 3;
    
    for(int i=0; i<=maxval; i++){
        for(int j=maxval-i; j>=0; j--){
            
            if((i*3+j*5) == n){
                minval = i + j;
                
                if(minval < ans)
                    ans = minval;
            }
        }
    }
    
    if(ans == 987654321)
        cout << "-1\n";
    else
        cout << ans << "\n";
    
    return 0;
}
