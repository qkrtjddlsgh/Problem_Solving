// 알파벳
#include <bits/stdc++.h>
using namespace std;

int r, c, cnt, visit[21][21], alpha[101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char input[21][21];

void dfs(int x, int y){
    cnt++;
    printf("%d %d ", x, y);
    alpha[input[x][y]] = 0;
    visit[x][y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < r && ny < c && visit[nx][ny] == 0 && alpha[input[nx][ny]]){
            dfs(nx, ny);
            //alpha[input[nx][ny]] = 1;
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &r, &c);
    
    for(int k=65; k<=65+c; k++)
        alpha[k] = 1;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf(" %c", &input[i][j]);
        }
    }
    
    dfs(0, 0);
    
    printf("%d\n", cnt);
    return 0;
}
