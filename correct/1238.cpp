#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair <int, int> P;

int n, m, x;
int from, to, cost;

int dist[1001];
int result[1001];

vector <vector<P>> adj;
priority_queue <P, vector<P>, greater<P>> pq;

int main(int argc, const char * argv[]) {
    scanf("%d %d %d", &n, &m, &x);
    adj.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &from, &to, &cost);
        adj[from].push_back({to, cost});
    }
    
    for(int j=1; j<=n; j++){
        dist[j] = INF;
        result[j] = INF;
    }
    
    result[x] = 0;
    pq.push({0, x});
    
    while(!pq.empty()){
        int cst = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0; i<adj[cur].size(); i++){
            int there = adj[cur][i].first;
            int nextdist = cst + adj[cur][i].second;
            
            if(result[there] > nextdist){
                result[there] = nextdist;
                pq.push({nextdist, there});
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=n; j++)
            dist[j] = INF;
        
        dist[i] = 0;
        pq.push({0, i});
        
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
        result[i] = dist[x] + result[i];
    }
    
    int res=0;
    
    for(int i=1; i<=n; i++)
        res = max(res, result[i]);
    
    cout << res << "\n";
    
    return 0;
}

