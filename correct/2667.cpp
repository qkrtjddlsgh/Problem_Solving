// 단지번호붙이기
#include <bits/stdc++.h>
using namespace std;

int n, cnt, arr[26][26], visited[26][26];
vector <int> ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int _x, int _y){
    cnt++;
    visited[_x][_y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = _x + dx[i];
        int ny = _y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0 && arr[nx][ny] == 1){
            dfs(nx, ny);
        }
    }
    
    return;
}

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0 && arr[i][j] == 1){
                dfs(i, j);
                
                ans.push_back(cnt);
                cnt = 0;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    //printf("%d\n", ans.size());
    
    for(int i=0; i<ans.size(); i++)
        printf("%d\n", ans[i]);
    
    return 0;
}
