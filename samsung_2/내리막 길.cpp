// 내리막 길
#include <iostream>
#include <cstring>
using namespace std;

int n, m, arr[501][501], dp[501][501];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int func(int x, int y){
    if(x == 0 && y == 0)
        return 1;
    
    int &ret = dp[x][y];
    
    if(ret != -1)
        return ret;
    
    ret = 0;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx > m-1 || ny > n-1)
            continue;
        
        if(arr[x][y] < arr[nx][ny])
            ret += func(nx, ny);
    }
    
    return ret;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> m >> n;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    cout << func(m-1, n-1) << "\n";
    return 0;
}
