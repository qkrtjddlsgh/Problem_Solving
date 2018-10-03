// 로봇 청소기 : 계산 실수 조심!!
#include <iostream>
using namespace std;

int n, m, r, c, d, ans, dx[4], dy[4], tdir[4], arr[51][51], visited[51][51];

void dfs(int x, int y, int dir){
    visited[x][y] = 1;
    
    if(dir == 1){
        dx[0] = -1; dx[1] = 0; dx[2] = 1; dx[3] = 0;
        dy[0] = 0; dy[1] = -1; dy[2] = 0; dy[3] = 1;
        tdir[0] = 0; tdir[1] = 3; tdir[2] = 2; tdir[3] = 1;
    }
    else if(dir == 2){
        dx[0] = 0; dx[1] = -1; dx[2] = 0; dx[3] = 1;
        dy[0] = 1; dy[1] = 0; dy[2] = -1; dy[3] = 0;
        tdir[0] = 1; tdir[1] = 0; tdir[2] = 3; tdir[3] = 2;
    }
    else if(dir == 3){
        dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
        dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
        tdir[0] = 2; tdir[1] = 1; tdir[2] = 0; tdir[3] = 3;
    }
    else if(dir == 0){
        dx[0] = 0; dx[1] = 1; dx[2] = 0; dx[3] = -1;
        dy[0] = -1; dy[1] = 0; dy[2] = 1; dy[3] = 0;
        tdir[0] = 3; tdir[1] = 2; tdir[2] = 1; tdir[3] = 0;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !arr[nx][ny] && !visited[nx][ny]){
            return dfs(nx, ny, tdir[i]);
        }
    }
    
    int tx = x + dx[1];
    int ty = y + dy[1];
    
    if(tx >= 0 && ty >= 0 && tx < n && ty < m && !arr[tx][ty]){
        return dfs(tx, ty, dir);
    }
    else
        return;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m >> r >> c >> d;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    dfs(r, c, d);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]){
                ans++;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
