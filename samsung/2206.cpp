// 벽 부수고 이동하기
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, arr[1001][1001], visited[2][1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue <pair<int, pair<int,int>>> q; // bomb, x, y
    q.push({0, {x, y}});
    
    visited[0][x][y] = 1;
    visited[1][x][y] = 1;
    
    while(!q.empty()){
        int bomb = q.front().first;
        int nx = q.front().second.first;
        int ny = q.front().second.second;
        q.pop();
        
        if(nx == n-1 && ny == m-1)
            return;
        
        for(int i=0; i<4; i++){
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            
            if(nnx < 0 || nny < 0 || nnx >= n || nny >= m || visited[bomb][nnx][nny])
                continue;
            
            if(arr[nnx][nny] == 0){
                q.push({bomb, {nnx, nny}});
                
                if(bomb == 0){ // 아직 쓰지 않았지만 추후에 사용 가능하니 visited[1][nnx][nny]도 함께 업데이트
                    visited[0][nnx][nny] = visited[0][nx][ny] + 1;
                    visited[1][nnx][nny] = visited[0][nx][ny] + 1;
                }
                else{ // 이미 bomb을 썼으니 쓸 수 없음
                    visited[1][nnx][nny] = visited[1][nx][ny] + 1;
                }
            }
            else if(bomb == 0){ // 아직 bomb을 쓰지 않았다면 사용
                q.push({1, {nnx, nny}});
                visited[1][nnx][nny] = visited[1][nx][ny] + 1;
            }
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &arr[i][j]);
    
    bfs(0, 0);
    
    if(visited[1][n-1][m-1] == 0)
        printf("-1\n");
    else
        printf("%d\n", visited[1][n-1][m-1]);
    
    return 0;
}
