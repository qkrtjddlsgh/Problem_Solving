// N과 M (3) : 중복 가능한 모든 순서쌍
#include <iostream>
using namespace std;

int n, m, arr[9];

void func(int cur){
    if(cur == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }
    
    for(int i=1; i<=n; i++){
        arr[cur] = i;
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    func(0);
    
    return 0;
}
