// 홈 방범 서비스
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int tc, n, m, ans, cnt, arr[21][21], visited[21][21];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int count){
    visited[x][y] = 1;
    
    if(arr[x][y] == 1)
        cnt += 1;
    
    queue <pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        if(visited[nx][ny] > count)
            return;
        
        for(int i=0; i<4; i++){
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            
            if(nnx >=0 && nny >= 0 && nnx < n && nny < n && visited[nnx][nny] == 0){
                if(arr[nnx][nny] == 1)
                    cnt++;
                
                visited[nnx][nny] =  visited[nx][ny] + 1;
                q.push({nnx, nny});
            }
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> n >> m;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> arr[i][j];
        
        for(int k=2; k<=n+1; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cnt = 0; memset(visited, 0, sizeof(visited));
                    bfs(i, j, k);
                    
                    if(m * cnt - (k * k + (k - 1) * (k - 1)) >= 0)
                        ans = max(ans, cnt);
                }
            }
        }
        
        cout << "#" << t << " " << ans << "\n";
        memset(arr, 0, sizeof(arr)); ans = 0;
    }
    
    return 0;
}
