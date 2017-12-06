// 특정한 최단 경로
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair <int, int> P;

int n, e;
int from, to, cost;
int st, en;

vector <vector<P>> adj; queue <int> q;
priority_queue <P, vector<P>, greater<P>> pq;

vector <int> dijkstra(int src){
    vector <int> dist(n + 1, INF);
    
    dist[src] = 0;
    pq.push({0, src});
    
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

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &e);
    adj.resize(n+1);
    
    for(int i=0; i<e; i++){
        scanf("%d %d %d", &from, &to, &cost);
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
    
    scanf("%d %d", &st, &en);
    
    q.push(1); q.push(st);
    q.push(st); q.push(en);
    q.push(en); q.push(n);
    
    q.push(1); q.push(en);
    q.push(en); q.push(st);
    q.push(st); q.push(n);
    
    vector <int> rev1;
    vector <int> rev2;
    int res[6] = {0, 0, 0, 0, 0, 0};
    
    for(int i=0; i<6; i++){
        int temp1 = q.front(); q.pop();
        int temp2 = q.front(); q.pop();
        
        rev1 = dijkstra(temp1);
        res[i] = rev1[temp2];
        
        if(res[i] == INF){
            printf("-1\n");
            return 0;
        }
    }

    res[0] = min(res[0]+res[1]+res[2], res[3]+res[4]+res[5]);
    printf("%d\n", res[0]);
    return 0;
}
