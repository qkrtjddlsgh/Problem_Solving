// 테트로미노
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, ans1, ans2, arr[501][501], visited[501][501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, int sum){
    if(cnt == 4){
        ans1 = max(ans1, sum);
        return;
    }
    
    visited[x][y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >=0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0){
            dfs(nx, ny, cnt + 1, sum + arr[nx][ny]);
        }
    }
    
    visited[x][y] = 0;
}

void func(int x, int y){
    
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dfs(i, j, 1, arr[i][j]);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
