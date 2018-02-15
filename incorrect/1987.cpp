// 알파벳
#include <bits/stdc++.h>
using namespace std;

int r, c, cnt, chk[26];
char alpha[21][21];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int count){
    cnt = max(cnt, count);
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < r && ny < c && chk[alpha[nx][ny]-'A'] == 0){
            chk[alpha[nx][ny]-'A'] = 1;
            dfs(nx, ny, count+1);
            chk[alpha[nx][ny]-'A'] = 0;
        }
    }
    
    return;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            scanf(" %c", &alpha[i][j]);

    chk[alpha[0][0]-'A'] = 1;
    dfs(0, 0, 1);
    
    cout << cnt << "\n";
    return 0;
}
