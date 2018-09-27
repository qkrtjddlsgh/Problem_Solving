// 다리 만들기
#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, cnt = 1, minVal = 987654321, arr[101][101], visited[101][101], visited_2[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

queue <pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            
            if(nnx >= 0 && nny >= 0 && nnx < n && nny < n && visited_2[nnx][nny] == 0){
                q.push({nnx, nny});
                visited_2[nnx][nny] = visited_2[nx][ny] + 1;
            }
        }
    }
}

void dfs(int x, int y, int cnt){
    visited[x][y] = cnt;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0 && arr[nx][ny]){
            dfs(nx, ny, cnt);
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }
    
    for(int k=1; k<cnt; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == k){
                    q.push({i, j});
                    visited_2[i][j] = 1;
                }
            }
        }
        
        bfs();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] != k && visited[i][j] != 0){
                    minVal = min(minVal, visited_2[i][j] - 1);
                }
            }
        }
        
        memset(visited_2, 0, sizeof(visited_2));
    }
    
    cout << minVal - 1 << "\n";
    return 0;
}
