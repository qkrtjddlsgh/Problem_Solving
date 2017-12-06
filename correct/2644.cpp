// 촌수 계산
#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, from, to, visit[101];
vector <vector<int>> adj;

void bfs(int node){
    queue <int> q;
    q.push(node);
    visit[node] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(auto i : adj[cur]){
            if(visit[i] == 0){
                q.push(i);
                visit[i] = visit[cur] + 1;
            }
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d %d %d", &n, &s, &e, &m);
    adj.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &from, &to);
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    bfs(s);
    
    if(visit[e] == 0)
        printf("-1\n");
    else
        printf("%d\n", visit[e]-1);
    
    return 0;
}
