// 탈주범 검거
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int tc, n, m, r, c, l, dir, ans, arr[51][51][5], visited[51][51], dx[4], dy[4];

void bfs(int x, int y, int time){
    visited[x][y] = 1;
    
    queue <pair<int,pair<int,int>>> q;
    q.push({time-1, {x, y}}); // 2, 2, 1
    
    while(!q.empty()){
        int cur = q.front().first;
        int nx = q.front().second.first;
        int ny = q.front().second.second;
        q.pop();
        
        if(arr[nx][ny][0] == 1){
            dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
            dy[0] = 0; dy[1] = 0; dy[2] = -1; dy[3] = 1;
        }
        else if(arr[nx][ny][0] == 2){
            dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
            dy[0] = 0; dy[1] = 0; dy[2] = 0; dy[3] = 0;
        }
        else if(arr[nx][ny][0] == 3){
            dx[0] = 0; dx[1] = 0; dx[2] = 0; dx[3] = 0;
            dy[0] = -1; dy[1] = 1; dy[2] = 0; dy[3] = 0;
        }
        else if(arr[nx][ny][0] == 4){
            dx[0] = -1; dx[1] = 0; dx[2] = 0; dx[3] = 0;
            dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = 0;
        }
        else if(arr[nx][ny][0] == 5){
            dx[0] = 1; dx[1] = 0; dx[2] = 0; dx[3] = 0;
            dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = 0;
        }
        else if(arr[nx][ny][0] == 6){
            dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = 0;
            dy[0] = -1; dy[1] = 0; dy[2] = 0; dy[3] = 0;
        }
        else if(arr[nx][ny][0] == 7){
            dx[0] = -1; dx[1] = 0; dx[2] = 0; dx[3] = 0;
            dy[0] = 0; dy[1] = -1; dy[2] = 0; dy[3] = 0;
        }
        
        for(int i=0; i<4; i++){
            if(dx[i] == 0 && dy[i] == 0)
                continue;
            else{
                int nnx = nx + dx[i];
                int nny = ny + dy[i];
                
                if(dx[i] == -1 && dy[i] == 0)
                    dir = 2;
                if(dx[i] == 1 && dy[i] == 0)
                    dir = 1;
                if(dx[i] == 0 && dy[i] == -1)
                    dir = 4;
                if(dx[i] == 0 && dy[i] == 1)
                    dir = 3;
                
                if(nnx >= 0 && nny >= 0 && nnx < n && nny < m && visited[nnx][nny] == 0 && cur >= 1 && arr[nnx][nny][0] != 0 && arr[nnx][nny][dir]){
                    visited[nnx][nny] = 1;
                    q.push({cur-1, {nnx, nny}});
                }
            }
        }
        
    }
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                scanf("%d", &arr[i][j][0]);
                
                // 상하좌우
                if(arr[i][j][0] == 1){
                    for(int k=1; k<5; k++)
                        arr[i][j][k] = 1;
                }
                else if(arr[i][j][0] == 2){
                    arr[i][j][1] = 1;
                    arr[i][j][2] = 1;
                }
                else if(arr[i][j][0] == 3){
                    arr[i][j][3] = 1;
                    arr[i][j][4] = 1;
                }
                else if(arr[i][j][0] == 4){
                    arr[i][j][1] = 1;
                    arr[i][j][4] = 1;
                }
                else if(arr[i][j][0] == 5){
                    arr[i][j][2] = 1;
                    arr[i][j][4] = 1;
                }
                else if(arr[i][j][0] == 6){
                    arr[i][j][2] = 1;
                    arr[i][j][3] = 1;
                }
                else if(arr[i][j][0] == 7){
                    arr[i][j][1] = 1;
                    arr[i][j][3] = 1;
                }
            }
        }
        
        bfs(r, c, l);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 1)
                    ans++;
            }
        }
        
        printf("#%d %d\n", h+1, ans);
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        ans = 0;
    }
    
    return 0;
}
