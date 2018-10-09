// 테트로미노 : DFS 탐색 + 예외 케이스
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans, arr[501][501], visited[501][501];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void func(int x, int y, int cnt, int sum){
    if(cnt == 4){
        ans = max(ans, sum);
        return;
    }
    
    visited[x][y] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0){
            func(nx, ny, cnt + 1, sum + arr[nx][ny]);
        }
    }
    
    visited[x][y] = 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            func(i, j, 1, arr[i][j]);
            
            if(i > 0 && j > 0 && i < n - 1 && j < m - 1){ // 가운데
                ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j-1] + arr[i-1][j]); // ㅗ
                ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j]); // ㅜ
                ans = max(ans, arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j+1]); // ㅏ
                ans = max(ans, arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j-1]); // ㅓ
            }
            if(i == 0 && j > 0 && j < m - 1){
                ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j]); // ㅜ
            }
            if(j == 0 && i > 0 && i < n - 1){
                ans = max(ans, arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j+1]); // ㅏ
            }
            if(i == n - 1 && j > 0 && j < m - 1){
                ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j-1] + arr[i-1][j]); // ㅗ
            }
            if(j == m - 1 && i > 0 && i < n - 1){
                ans = max(ans, arr[i][j] + arr[i-1][j] + arr[i+1][j] + arr[i][j-1]); // ㅓ
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
