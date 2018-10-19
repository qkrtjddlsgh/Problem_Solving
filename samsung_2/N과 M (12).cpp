// N과 M (12)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t, d, arr[9], visited[9];

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
        return;
    }
    
    for(int i=0; i<v.size(); i++){
        arr[cur] = v[i];
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> t;
        
        for(int j=0; j<v.size(); j++){
            if(v[j] == t)
                d = 1;
        }
        
        if(d == 0)
            v.push_back(t);
        
        d = 0;
    }
    
    sort(v.begin(), v.end());
    
    func(0);
    
    return 0;
}
