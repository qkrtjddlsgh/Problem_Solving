// 연구소
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m, ans, cnt, arr[9][9], visited[9][9];

vector <pair<int,int>> v;
vector <pair<int,int>> s;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0 && arr[nx][ny] == 0){
            visited[nx][ny] = visited[x][y] + 1;
            dfs(nx, ny);
        }
    }
    
    return;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
            
            if(arr[i][j] == 0) // 벽으로 바꿀 점
                v.push_back({i, j});
            if(arr[i][j] == 2) // dfs 탐색 시작점
                s.push_back({i, j});
        }
    
    // 0 : 빈칸, 1 : 벽, 2 : 바이러스
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                visited[v[i].first][v[i].second] = 1;
                visited[v[j].first][v[j].second] = 1;
                visited[v[k].first][v[k].second] = 1;
                
                for(int l=0; l<s.size(); l++){
                    if(visited[s[l].first][s[l].second] == 0){
                        visited[s[l].first][s[l].second] = 1;
                        dfs(s[l].first, s[l].second);
                    }
                }
                
                for(int a=0; a<n; a++){
                    for(int b=0; b<m; b++){
                        if(visited[a][b] == 0 && arr[a][b] == 0)
                            cnt++;
                    }
                }
                
                ans = max(ans, cnt); cnt = 0;
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
