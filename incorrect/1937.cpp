// 욕심쟁이 판다
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, arr[501][501], dp[501][501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y){
    if(dp[x][y] == 0){
        dp[x][y] = 1;
    
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] > arr[x][y]){
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
            }
        }
    }
    
    return dp[x][y];
}

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    
    printf("%d\n", ans);
    return 0;
}
