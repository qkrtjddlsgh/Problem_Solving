#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n, m;
int from, to, cost;
int dist[101][101];

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i != j)
                dist[i][j] = INF;
        }
    }
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &from, &to, &cost);
        dist[from-1][to-1] = min(dist[from-1][to-1], cost);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
