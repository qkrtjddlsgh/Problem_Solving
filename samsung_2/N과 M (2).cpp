// N과 M (2) : 모든 순서쌍 구하기
#include <iostream>
using namespace std;

int n, m, visited[9];

void func(int num, int cnt){
    visited[num] = 1;
    
    if(cnt == m){
        for(int i=1; i<=n; i++){
            if(visited[i]){
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    else{
        for(int i=num+1; i<=n; i++){
            func(i, cnt + 1);
        }
    }
    
    visited[num] = 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        func(i, 1);
    }
    
    return 0;
}
