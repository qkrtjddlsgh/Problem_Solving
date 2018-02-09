// N-Queen
#include <bits/stdc++.h>
using namespace std;

// n은 퀸의 갯수
int n, cnt, arr[16];

void func(int h){
    
    if(h == n){ // 마지막행까지 갔을때
        cnt++;
        return;
    }
    
    for(int i=0; i<n; i++){
        bool flag = false;
        
        for(int j=0; j<h; j++){
            if (arr[j] == i || abs(i-arr[j]) == abs(h-j)) {
                flag = true;
                break;
            }
        }
        
        if(flag)
            continue;
        
        arr[h] = i;
        func(h+1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    func(0);
    
    cout << cnt << "\n";
    return 0;
}
