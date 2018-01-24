// 하얀 칸
#include <bits/stdc++.h>
using namespace std;

char c;
int cnt;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> c;
            
            if(i%2 == 0 && j%2 == 0 && c == 'F')
                cnt++;
            if(i%2 == 1 && j%2 == 1 && c == 'F')
                cnt++;
            
            // 0 2 4 6 // 0 2 4 6
            // 1 3 5 7 // 1 3 5 7
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
