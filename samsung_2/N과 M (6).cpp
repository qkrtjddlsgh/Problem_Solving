// N과 M (6)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, t, visited[10001];

vector <int> v;

void func(int num, int cnt){
    visited[v[num]] = 1;
    
    if(cnt == m){
        for(int i=0; i<10001; i++){
            if(visited[i]){
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    else{
        for(int i=num+1; i<v.size(); i++){
            func(i, cnt + 1);
        }
    }
    
    visited[v[num]] = 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        func(i, 1);
    }
    
    return 0;
}
