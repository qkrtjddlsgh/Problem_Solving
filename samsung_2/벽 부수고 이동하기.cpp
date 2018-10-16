// 벽 부수고 이동하기
#include <iostream>
#include <queue>
using namespace std;

int n, m, arr[1001][1001], visited[2][1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int wall){
    visited[0][x][y] = 1;
    visited[1][x][y] = 1;
    
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
            
            if(nnx < 1 || nny < 1 || nnx > n || nny > m || visited[wall][nnx][nny])
                continue;
            
            if(arr[nnx][nny] == 0){ // 갈 수 있는 경우
                q.push({wall, {nnx, nny}});
                
                if(wall == 0){
                    visited[0][nnx][nny] = visited[0][nx][ny] + 1;
                    visited[1][nnx][nny] = visited[0][nx][ny] + 1;
                }
                else{
                    visited[1][nnx][nny] = visited[1][nx][ny] + 1;
                }
            }
            else if(wall == 0){ // 벽 부수기
                visited[1][nnx][nny] = visited[1][nx][ny] + 1;
                q.push({1, {nnx, nny}});
            }
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%1d", &arr[i][j]);
    
    bfs(1, 1, 0);
    
    if(visited[1][n][m] == 0)
        printf("-1\n");
    else
        printf("%d\n", visited[1][n][m]);
    
    return 0;
}
