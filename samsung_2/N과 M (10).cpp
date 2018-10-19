// N과 M (10)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, e, arr[9], visited[9];

vector <int> v;

void func(int cur){
    if(cur == m){
        for(int i=1; i<m; i++){
            if(arr[i] < arr[i-1])
                return;
        }
        
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    int chk[10001] = {0, };
    
    for(int i=0; i<v.size(); i++){
        if(!visited[i] && !chk[v[i]]){
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
        cin >> e;
        v.push_back(e);
    }
    
    sort(v.begin(), v.end());
    
    func(0);
    
    return 0;
}
