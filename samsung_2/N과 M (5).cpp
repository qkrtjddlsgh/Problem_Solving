// N과 M (5)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, t, arr[9], visited[10001];

vector <int> v;

void func(int cur){
    if(cur == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    
    for(int i=0; i<v.size(); i++){
        if(!visited[v[i]]){
            visited[v[i]] = 1;
            
            arr[cur] = v[i];
            func(cur + 1);
            
            visited[v[i]] = 0;
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
