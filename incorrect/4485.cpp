// 녹색 옷 입은 애가 젤다지?
#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int n;

int input[126][126];
int dist[126][126];

int main(int argc, char *argv[]){
    int tc=0;
    
    do{
        scanf("%d", &n);
        tc++;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &input[i][j]);
                
                if(i != j)
                    dist[i][j] = INF;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
        
        printf("Problem %d: %d\n", tc, dist[n-1][n-1]);
        memset(input, 0, sizeof(input));
        
    }while(n != 0);
    
    return 0;
}
