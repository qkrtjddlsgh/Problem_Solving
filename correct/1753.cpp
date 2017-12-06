#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair <int, int> P;

int v, e, k;
int from, to, cost;

int dist[20001];

vector <vector<P>> adj;
priority_queue <P, vector<P>, greater<P>> pq;

int main(int argc, const char * argv[]) {
    scanf("%d %d", &v, &e);
    scanf("%d", &k);
    adj.resize(v+1);
    
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &from, &to, &cost);
        adj[from].push_back({to, cost});
    }
    
    for(int i=1; i<=v; i++)
        dist[i] = INF;
    
    dist[k] = 0;
    pq.push({0, k});
    
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
    
    for(int i=1; i<=v; i++){
        if(dist[i] == 987654321)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
    
    return 0;
}
