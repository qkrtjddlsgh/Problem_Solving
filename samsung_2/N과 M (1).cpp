// N과 M (1)
#include <iostream>
using namespace std;

int n, m, visited[9];

void func(int index, int cnt){
    visited[index] = 1;
    
    if(index > n)
        return;
    if(cnt == m){
        for(int i=1; i<=n; i++){
            if(visited[i]){
                cout << i << " ";
            }
        }
        cout << "\n";
        return;
    }
    
    func(index + 1, cnt);
    func(index + 1, cnt + 1);
    
    visited[index] = 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    func(0, 0);
    
    return 0;
}
