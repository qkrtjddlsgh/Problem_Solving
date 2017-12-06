// 서강 그라운드
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
typedef pair<int,int> P;

int n, m, r, from, to, cost, result, ans;
int item[101];

vector <vector<P>> adj;
priority_queue <P, vector<P>, greater<P>> pq;

vector <int> dijkstra(int src){
    vector <int> dist(n + 1, INF);
    vector <int> visit(n + 1, 0);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()){
        int cur;
        
        do{
            cur = pq.top().second;
            pq.pop();
        } while(!pq.empty() && visit[cur]);
        
        if(visit[cur])
            break;
        
        visit[cur]++;
        
        for(auto i : adj[cur]){
            if(dist[i.first] > dist[cur] + i.second){
                dist[i.first] = dist[cur] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    
    return dist;
}

int main(int argc, char *argv[]){
    scanf("%d %d %d", &n, &m, &r);
    adj.resize(n+1);
    
    for(int i=1; i<=n; i++)
        scanf("%d", &item[i]);
    
    for(int i=0; i<r; i++){
        scanf("%d %d %d", &from, &to, &cost);
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
    
    for(int i=1; i<=n; i++){
        vector <int> res;
        res = dijkstra(i);
        
        for(int j=1; j<=n; j++){
            if(res[j] <= r)
                result += item[j];
        }
        
        ans = max(ans, result);
        result = 0;
    }
    
    printf("%d\n", ans);
    return 0;
}
