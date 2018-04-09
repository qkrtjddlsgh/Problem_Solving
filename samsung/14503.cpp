// 로봇 청소기
#include <iostream>
using namespace std;

int n, m, r, c, d, ans, arr[51][51], visited[51][51];

// dir : 0-북->3, 1-동->0, 2-남->1, 3-서->2

void dfs(int x, int y, int dir){
    if(x < 0 || y < 0 || x >= n || y >= m)
        return;
    
    if(dir == 0){
        if(arr[x][y-1] == 0 && visited[x][y-1] == 0 && x >= 0 && y-1 >= 0 && x < n && y-1 < m){
            visited[x][y-1] = 1; // 현재 위치 청소
            dfs(x, y-1, 3); // 왼쪽 청소
        }
        else if((arr[x][y-1] == 1 || visited[x][y-1] == 1) && x >= 0 && y-1 >= 0 && x < n && y-1 < m)
            dfs(x, y, 3);
        
        // 네 방향 다 갈 수 없을때
        else if(visited[x][y-1] && visited[x-1][y] && visited[x+1][y] && visited[x][y+1] && arr[x+1][y] == 0) // 모두 방문했거나
            dfs(x+1, y, 0);
    }
    else if(dir == 1){
        if(arr[x-1][y] == 0 && visited[x-1][y] == 0 && x-1 >= 0 && y >= 0 && x-1 < n && y < m){
            visited[x-1][y] = 1; // 현재 위치 청소
            dfs(x-1, y, 0); // 왼쪽 청소
        }
        else if((arr[x-1][y] == 1 || visited[x-1][y] == 1) && x-1 >= 0 && y >= 0 && x-1 < n && y < m)
            dfs(x, y, 0);
        
        // 네 방향 다 갈 수 없을때
        else if(visited[x][y-1] && visited[x-1][y] && visited[x+1][y] && visited[x][y+1] && arr[x][y-1] == 0) // 모두 방문했거나
            dfs(x, y-1, 1);
    }
    else if(dir == 2){
        if(arr[x][y+1] == 0 && visited[x][y+1] == 0 && x >= 0 && y+1 >= 0 && x < n && y+1 < m){
            visited[x][y+1] = 1; // 현재 위치 청소
            dfs(x, y+1, 1); // 왼쪽 청소
        }
        else if((arr[x][y+1] == 1 || visited[x][y+1] == 1) && x >= 0 && y+1 >= 0 && x < n && y+1 < m)
            dfs(x, y, 1);
        
        // 네 방향 다 갈 수 없을때
        else if(visited[x][y-1] && visited[x-1][y] && visited[x+1][y] && visited[x][y+1] && arr[x-1][y] == 0) // 모두 방문했거나
            dfs(x-1, y, 2);
    }
    else if(dir == 3){
        if(arr[x+1][y] == 0 && visited[x+1][y] == 0 && x+1 >= 0 && y >= 0 && x+1 < n && y < m){
            visited[x+1][y] = 1; // 현재 위치 청소
            dfs(x+1, y, 2); // 왼쪽 청소
        }
        else if((arr[x+1][y] == 1 || visited[x+1][y] == 1) && x+1 >= 0 && y >= 0 && x+1 < n && y < m)
            dfs(x, y, 2);
        
        // 네 방향 다 갈 수 없을때
        else if(visited[x][y-1] && visited[x-1][y] && visited[x+1][y] && visited[x][y+1] && arr[x][y+1] == 0) // 모두 방문했거나
            dfs(x, y+1, 3);
    }
    return;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            // 0 : 빈칸, 1 : 벽
            scanf("%d", &arr[i][j]);
    
    visited[r][c] = 1;
    dfs(r, c, d);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 0 && visited[i][j] == 1)
                ans++;
        }
    }
    
    //printf("%d\n", ans);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", visited[i][j]);
        }
        cout << endl;
    }
    
    return 0;
}
