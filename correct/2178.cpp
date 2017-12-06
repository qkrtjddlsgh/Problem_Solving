// 미로 탐색
#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int input[101][101];

void bfs(int x, int y){
    queue <pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && input[nx][ny] == 1){
                q.push({nx, ny});
                input[nx][ny] = input[x][y] + 1;
            }
        }
    }
    
    
    return;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &input[i][j]);
        }
    }
    
    bfs(0, 0);
    printf("%d\n", input[n-1][m-1]);
    
    return 0;
}

