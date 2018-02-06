// 유기농 배추
#include <bits/stdc++.h>
using namespace std;

int tc, m, n, k, x, y, cnt;
int arr[2501][2501], visited[2501][2501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int _x, int _y){
    visited[_x][_y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = _x + dx[i];
        int ny = _y + dy[i];
        
        if(nx >=0 && ny >= 0 && nx < m && ny < n && visited[nx][ny] == 0 && arr[nx][ny] == 1)
            dfs(nx, ny);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    while(tc--){
        cin >> m >> n >> k;
        
        for(int i=0; i<k; i++){
            cin >> x >> y;
            arr[x][y] = 1;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == 1 && visited[i][j] == 0){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        cout << cnt << "\n";
        
        cnt = 0;
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
    }
    
    return 0;
}
