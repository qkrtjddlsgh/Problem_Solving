// 쉽게 푸는 문제
#include <bits/stdc++.h>
using namespace std;

int a, b, cnt, sum;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> a >> b;
    
    for(int i=1; i<=b; i++){
        for(int j=1; j<=i; j++){
            cnt++;
            
            if(cnt == a){
                cout << i << endl;
                break;
            }
        }
    }
    
    
    return 0;
}
