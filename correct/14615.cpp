// Defend the CTP!!!
#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, tc, visit[100001], rvisit[100001];
vector <vector<int>> adj;
vector <vector<int>> radj;

void dfs(int node){
    visit[node] = 1;
    
    for(auto i : adj[node]){
        if(!visit[i])
            dfs(i);
    }
}

void rdfs(int node){
    rvisit[node] = 1;
    
    for(auto i : radj[node]){
        if(!rvisit[i])
            rdfs(i);
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    adj.resize(n+1);
    radj.resize(n+1);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    
    scanf("%d", &tc);
    
    dfs(1);
    rdfs(n);
    
    while(tc--){
        int temp;
        scanf("%d", &temp);
        
        if(visit[temp] == 1 && rvisit[temp] == 1)
            printf("Defend the CTP\n");
        else
            printf("Destroyed the CTP\n");
    }
    
    return 0;
}

