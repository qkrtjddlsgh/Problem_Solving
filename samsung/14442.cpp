// 벽 부수고 이동하기 2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, arr[1001][1001], visited[11][1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector <int> ans;

void bfs(int x, int y){
    queue <pair<int, pair<int,int>>> q;
    q.push({0, {x, y}});
    
    for(int i=0; i<=k; i++)
        visited[i][0][0] = 1;
    
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
                
                if(bomb < k){ // 아직 부술수 있는 경우
                    for(int j=bomb; j<=k; j++){
                        visited[j][nnx][nny] = visited[bomb][nx][ny] + 1;
                    }
                }
                else{ // 더이상 벽을 부술수 없는 경우
                    visited[k][nnx][nny] = visited[k][nx][ny] + 1;
                }
            }
            else if(bomb < k){ // 부수는 경우
                q.push({bomb+1, {nnx, nny}});
                
                for(int j=bomb+1; j<=k; j++){
                    visited[j][nnx][nny] = visited[bomb+1][nx][ny] + 1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%1d", &arr[i][j]);
    
    bfs(0, 0);
    
    for(int i=0; i<=k; i++)
        ans.push_back(visited[i][n-1][m-1]);
    
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++){
        if(ans[ans.size()-1] == 0)
            printf("-1\n");
        if(ans[i] != 0){
            printf("%d\n", ans[i]);
            break;
        }
    }
    
    return 0;
}
