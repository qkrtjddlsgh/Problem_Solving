// 안전영역
#include <bits/stdc++.h>
using namespace std;

int n, cnt, maxcnt, maxval, arr[101][101], visited[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int _x, int _y, int rain){
    visited[_x][_y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = _x + dx[i];
        int ny = _y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0 && arr[nx][ny] > rain){
            dfs(nx, ny, rain);
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            maxval = max(maxval, arr[i][j]);
        }
    }
    
    for(int k=0; k<=maxval; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && arr[i][j] > k){
                    cnt++;
                    dfs(i, j, k);
                }
            }
        }
        
        maxcnt = max(maxcnt, cnt);
        cnt = 0;
        memset(visited, 0, sizeof(visited));
    }
    
    cout << maxcnt << "\n";
    return 0;
}
