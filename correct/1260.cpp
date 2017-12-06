// DFS와 BFS
#include <bits/stdc++.h>
using namespace std;

int n, m, s, from, to, visited[1001];
vector <vector <int>> adj;

void dfs(int node){
    visited[node] = 1;
    printf("%d ", node);
    
    for(auto i : adj[node]){
        if(!visited[i])
            dfs(i);
    }
    
    return;
}

void bfs(int node){
    queue <int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        printf("%d ", cur);
        q.pop();
        
        for(auto i : adj[cur]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d %d", &n, &m, &s);
    adj.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    for(int i=0; i<adj.size(); i++)
        sort(adj[i].begin(), adj[i].end());
    
    memset(visited, 0, sizeof(visited));
    
    dfs(s);
    printf("\n");
    
    memset(visited, 0, sizeof(visited));
    
    bfs(s);
    printf("\n");
    
    return 0;
}
