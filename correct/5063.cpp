// TGN
#include <bits/stdc++.h>
using namespace std;

int r, e, c;

int main(int argc, char *argv[]){
    int tc;
    scanf("%d", &tc);
    
    while(tc--){
        scanf("%d %d %d", &r, &e, &c);
        
        if(r < e - c)
            cout << "advertise\n";
        else if(r == e - c)
            cout << "does not matter\n";
        else
            cout << "do not advertise\n";
    }
    
    return 0;
}
