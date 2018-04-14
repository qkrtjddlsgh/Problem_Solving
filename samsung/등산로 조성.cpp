// 등산로 조성
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int tc, n, k, cnt, ans, temp, maxh, arr[9][9], visited[9][9];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector <pair<int,int>> v;

void dfs(int x, int y, int cut){
    visited[x][y] = 1;
    cnt++;
    
    ans = max(cnt, ans);
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(cut == 0){
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] < arr[x][y]){
                dfs(nx, ny, 0);
            }
        }
        else{
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] < arr[x][y]){
                dfs(nx, ny, cut);
            }
            else if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] - cut < arr[x][y]){
                temp = arr[nx][ny];
                
                arr[nx][ny] = arr[x][y] - 1;
                dfs(nx, ny, 0);
                
                arr[nx][ny] = temp;
            }
        }
    }
    
    visited[x][y] = 0;
    cnt--;
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        scanf("%d %d", &n, &k);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &arr[i][j]);
                maxh = max(maxh, arr[i][j]); // 시작점
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] == maxh){
                    v.push_back({i, j});
                }
            }
        }
        
        for(int i=0; i<v.size(); i++){
            dfs(v[i].first, v[i].second, k);
            
            memset(visited, 0, sizeof(visited));
            cnt = 0;
        }
        
        printf("#%d %d\n", h+1, ans);
        
        memset(arr, 0, sizeof(arr));
        v.clear(); maxh = 0; ans = 0; temp = 0;
    }
    
    return 0;
}
