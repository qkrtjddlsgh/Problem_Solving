// 적록색약
#include <bits/stdc++.h>
using namespace std;

int n, cnt, cnt2, visit[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char input[101][101];

void dfs(int x, int y, char what){
    visit[x][y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && visit[nx][ny] == 0 && input[nx][ny] == what){
            dfs(nx, ny, input[nx][ny]);
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf(" %c", &input[i][j]);
        }
    }
    
    memset(visit, 0, sizeof(visit));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == 0){
                dfs(i, j, input[i][j]);
                cnt++;
            }
        }
    }
        
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(input[i][j] == 'R')
                input[i][j] = 'G';
        }
    }
    
    memset(visit, 0, sizeof(visit));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j] == 0){
                dfs(i, j, input[i][j]);
                cnt2++;
            }
        }
    }
    
    printf("%d %d\n", cnt, cnt2);
    return 0;
}
