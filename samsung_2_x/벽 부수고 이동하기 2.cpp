// 벽 부수고 이동하기 2
#include <iostream>
#include <queue>
using namespace std;

int n, m, k, arr[1001][1001], visited[11][1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int wall){
    for(int i=0; i<=k; i++)
        visited[i][x][y] = 1;
    
    queue <pair<int,pair<int,int>>> q;
    q.push({wall, {x, y}});
    
    while(!q.empty()){
        int wall = q.front().first;
        int nx = q.front().second.first;
        int ny = q.front().second.second;
        q.pop();
        
        if(nx == n && ny == m)
            return;
        
        for(int i=0; i<4; i++){
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            
            if(nnx < 1 || nny < 1 || nnx > n || nny > m || visited[k][nnx][nny])
                continue;
            
            if(arr[nnx][nny] == 0){ // 그냥 갈수있는 경우
                q.push({wall, {nnx, nny}});
                
                if(wall == k){
                    visited[k][nnx][nny] = visited[k][nx][ny] + 1;
                }
                else{
                    for(int j=0; j<=k; j++){
                        visited[j][nnx][nny] = visited[0][nx][ny] + 1;
                    }
                }
            }
            else if(wall < k && arr[nnx][nny]){ // 부수는 경우
                q.push({wall + 1, {nnx, nny}});
                
                for(int j=wall+1; j<=k; j++){
                    visited[j][nnx][nny] = visited[wall+1][nx][ny] + 1;
                }
            }
            else if(wall == k && arr[nnx][nny] == 0){ // 더이상 못부수는 경우
                q.push({k, {nnx, nny}});
                visited[k][nnx][nny] = visited[k][nx][ny] + 1;
            }
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%1d", &arr[i][j]);
    
    bfs(1, 1, 0);
    
    if(visited[k][n][m] == 0)
        printf("-1\n");
    else
        printf("%d\n", visited[k][n][m]);
    
    return 0;
}
