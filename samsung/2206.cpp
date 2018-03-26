// 벽 부수고 이동하기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int n, m, arr[1001][1001], visited[1001][1001][2];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector <pair<int,int>> v;
vector <int> ans;

/*void bfs(int x, int y){
    visited[x][y] = 1;
    queue <pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            
            if(nnx >= 1 && nny >= 1 && nnx <= n && nny <= m && visited[nnx][nny] == 0 && arr[nnx][nny] == 0){
                visited[nnx][nny] = visited[nx][ny] + 1;
                q.push({nnx, nny});
            }
        }
    }
}*/

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]);
            
            if(arr[i][j] == 1)
                v.push_back({i, j});
        }
    }
    
    /*for(int k=0; k<v.size(); k++){
        arr[v[k].first][v[k].second] = 0; // 벽 부수기
        
        bfs(1, 1);
        ans.push_back(visited[n][m]);
        
        if(visited[n][m] == n+m) // 이미 최단경로일때
            break;
        
        memset(visited, 0, sizeof(visited));
        arr[v[k].first][v[k].second] = 1;
    }
    
    sort(ans.begin(), ans.end());
    
    if(ans[ans.size()-1] == 0)
        printf("-1\n");
    else{
        for(int i=0; i<ans.size(); i++){
            if(ans[i] != 0)
                printf("%d\n", ans[i]);
        }
    }*/
    
    return 0;
}
