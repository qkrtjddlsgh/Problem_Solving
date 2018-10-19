// N과 M (9)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t, arr[9], visited[9];

vector <int> v;

void func(int cur){
    if(cur == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int chk[10001] = {0, };
    
    for(int i=0; i<v.size(); i++){
        if(!chk[v[i]] && !visited[i]){
            visited[i] = 1;
            chk[v[i]] = 1;
            
            arr[cur] = v[i];
            func(cur + 1);
            
            visited[i] = 0;
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    func(0);
    
    return 0;
}
