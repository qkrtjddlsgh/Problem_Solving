// 케빈 베이컨의 6단계 법칙
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair <int, int> P;

int n, m, from, to, res[101];

vector <vector<P>> adj; queue <int> q;
priority_queue <P, vector<P>, greater<P>> pq;

vector <int> dijktra(int node){
    vector <int> dist(n + 1, INF);
    
    dist[node] = 0;
    pq.push({0, node});
    
    while(!pq.empty()){
        int cst = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0; i<adj[cur].size(); i++){
            int there = adj[cur][i].first;
            int nextdist = cst + adj[cur][i].second;
            
            if(dist[there] > nextdist){
                dist[there] = nextdist;
                pq.push({nextdist, there});
            }
        }
    }
    
    return dist;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    adj.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &from, &to);
        adj[from].push_back({to, 1});
        adj[to].push_back({from, 1});
    }
    
    vector <int> result;
    
    for(int i=1; i<=n; i++){
        result = dijktra(i);
        
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            else res[i] += result[j];
        }
    }
    
    int real = 987654321, cnt = 0;
    
    for(int i=1; i<=n; i++){
        if(res[i] < real){
            real = res[i];
            cnt = i;
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}
