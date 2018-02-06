// DFS와 BFS
#include <bits/stdc++.h>
using namespace std;

int n, m, v, from, to, visited[1001];
vector <vector<int>> adj;

void dfs(int node){
    visited[node] = 1;
    cout << node << " ";
    
    for(auto i : adj[node])
        if(!visited[i])
            dfs(i);
    
    return;
}

void bfs(int node){
    queue <int> q;
    visited[node] = 1;
    q.push(node);
    
    while(!q.empty()){
        int here = q.front();
        cout << here << " ";
        q.pop();
        
        for(auto i : adj[here])
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
    }
    
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m >> v;
    adj.resize(n+1);
    
    for(int i=0; i<m; i++){
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    for(int i=0; i<adj.size(); i++)
        sort(adj[i].begin(), adj[i].end());
    
    dfs(v);
    cout << "\n";
    
    memset(visited, 0, sizeof(visited));
    
    bfs(v);
    cout << "\n";
    
    return 0;
}
