// 로봇 청소기
#include <iostream>
using namespace std;

int n, m, r, c, d, ans, arr[51][51], visited[51][51], dx[4], dy[4];

// dir : 0-북->3, 1-동->0, 2-남->1, 3-서->2

int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, -1, 0, 1};

void dfs(int x, int y, int dir){
    visited[x][y] = 1;
    
    int tdir = dir;
    
    if((dir - 1 + 4) % 4 == 0){
        dx[0] = -1; dx[1] = 0; dx[2] = 1; dx[3] = 0;
        dy[0] = 0; dy[1] = -1; dy[2] = 0; dy[3] = 1;
    }
    else if((dir - 1 + 4) % 4 == 1){
        dx[0] = 0; dx[1] = -1; dx[2] = 0; dx[3] = 1;
        dy[0] = 1; dy[1] = 0; dy[2] = -1; dy[3] = 0;
    }
    else if((dir - 1 + 4) % 4 == 2){
        dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
        dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
    }
    else if((dir - 1 + 4) % 4 == 3){
        dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = -1;
        dy[0] = -1; dy[1] = 0; dy[2] = 1; dy[3] = 0;
    }
    
    for(int i=0; i<4; i++){
        tdir = (tdir - 1 + 4) % 4;
        
        int tx = x + dx[i];
        int ty = y + dy[i];
        
        if(tx >= 0 && tx < n && ty >= 0 && ty < m && !arr[tx][ty] && !visited[tx][ty]){
            return dfs(tx, ty, tdir);
        }
    }
    
    int tx = x + dc[dir];
    int ty = y + dr[dir];
    
    if(tx >= 0 && tx < n && ty >= 0 && ty < m && !arr[tx][ty]){
        return dfs(tx, ty, dir);
    }
    
    return;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            // 0 : 빈칸, 1 : 벽
            scanf("%d", &arr[i][j]);
    
    dfs(r, c, d);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j])
                ans++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
