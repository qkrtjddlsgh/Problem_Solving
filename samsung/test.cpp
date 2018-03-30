// test
#include <iostream>
#include <string>
using namespace std;

int tc, cnt;
string a;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int i=1; i<=tc; i++){
        cin >> a;
        
        int sz = a.size();
        
        if(sz%2 == 0){
            for(int j=0; j<sz/2; j++){
                if(a[j] == a[sz-j-1])
                    cnt += 2;
            }
            
            if(cnt == sz)
                printf("#%d 1\n", i);
            else
                printf("#%d 0\n", i);
        }
        else{
            for(int j=0; j<sz/2; j++){
                if(a[j] == a[sz-j-1])
                    cnt += 2;
            }
            
            if(cnt + 1 == sz)
                printf("#%d 1\n", i);
            else
                printf("#%d 0\n", i);
        }
        
        cnt = 0;
    }
    
    return 0;
}
