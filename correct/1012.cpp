// 유기농 배추
#include <bits/stdc++.h>
using namespace std;

int tc, m, n, k, x, y, cnt, input[51][51], visit[51][51];
int dx[4] = {-1 , 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int _x, int _y){
    visit[_x][_y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = _x + dx[i];
        int ny = _y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < m && ny < n && visit[nx][ny] == 0 && input[nx][ny] == 1){
            dfs(nx, ny);
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    while(tc--){
        scanf("%d %d %d", &m, &n, &k);
        
        memset(input, 0, sizeof(input));
        memset(visit, 0, sizeof(visit));
        
        for(int i=0; i<k; i++){
            scanf("%d %d", &x, &y);
            input[x][y] = 1;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visit[i][j] == 0 && input[i][j] == 1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
        cnt = 0;
    }
    
    return 0;
}
