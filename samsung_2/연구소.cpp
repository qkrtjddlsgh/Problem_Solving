// 연구소 : 가능한 모든 경우 dfs탐색
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, cnt, ans, arr[9][9], visited[9][9];

vector <pair<int,int>> virus;
vector <pair<int,int>> ground;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y){
    visited[x][y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >=0 && nx < n && ny < m && !arr[nx][ny] && !visited[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 2){
                virus.push_back({i, j});
            }
            if(arr[i][j] == 0){
                ground.push_back({i, j});
            }
        }
    }
    
    for(int i=0; i<ground.size(); i++){
        for(int j=i+1; j<ground.size(); j++){
            for(int k=j+1; k<ground.size(); k++){
                arr[ground[i].first][ground[i].second] = 1;
                arr[ground[j].first][ground[j].second] = 1;
                arr[ground[k].first][ground[k].second] = 1;
                
                for(int g=0; g<virus.size(); g++){
                    dfs(virus[g].first, virus[g].second);
                }
                
                for(int a=0; a<n; a++){
                    for(int b=0; b<m; b++){
                        if(arr[a][b] == 0 && !visited[a][b]){
                            cnt++;
                        }
                    }
                }
                
                ans = max(ans, cnt);
                memset(visited, 0, sizeof(visited));
                cnt = 0;
                
                arr[ground[i].first][ground[i].second] = 0;
                arr[ground[j].first][ground[j].second] = 0;
                arr[ground[k].first][ground[k].second] = 0;
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
