// 미로탐색
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[101][101], visited[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int _x, int _y){
    queue <pair<int,int>> q;
    visited[_x][_y] = 1;
    q.push({_x, _y});
    
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int n_x = nx + dx[i];
            int n_y = ny + dy[i];
            
            if(n_x > 0 && n_y >0 && n_x <= n && n_y <= m && arr[n_x][n_y] == 1 && visited[n_x][n_y] == 0){
                visited[n_x][n_y] = visited[nx][ny] + 1;
                q.push({n_x, n_y});
            }
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    bfs(1, 1);
    
    printf("%d\n", visited[n][m]);
    return 0;
}
