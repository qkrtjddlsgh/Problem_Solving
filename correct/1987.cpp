// 알파벳
#include <bits/stdc++.h>
using namespace std;

int r, c, cnt, alpha[26];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char input[21][21];

void dfs(int x, int y, int count){
    if(count > cnt)
        cnt = count;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (alpha[input[nx][ny]-'A'] == 1)
            continue;
        
        alpha[input[nx][ny]-'A'] = 1;
        dfs(nx, ny, count + 1);
        alpha[input[nx][ny]-'A'] = 0;
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf(" %c", &input[i][j]);
        }
    }
    
    alpha[input[0][0]-'A'] = 1;
    dfs(0, 0, 1);
    
    printf("%d\n", cnt);
    return 0;
}
