// 경사로
#include <iostream>
#include <cstring>
using namespace std;

int N, L, ans[4], cnt, arr[101][101], chk[4][101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// {-1,0} : 위 {1,0} : 아래 {0,-1} : 왼쪽 {0,1} : 오른쪽

void dfs(int x, int y, int direct, int stair){
    // 기저조건
    if((direct == 0 && x == 0) || (direct == 1 && x == N-1) || (direct == 2 && y == 0) || (direct == 3 && y == N-1)){
        ans[direct]++;
        return;
    }
    
    if(arr[x+dx[direct]][y+dy[direct]] == arr[x][y]){ // 같은 높이일 경우
        dfs(x+dx[direct], y+dy[direct], direct, stair);
    }
    if(arr[x+dx[direct]][y+dy[direct]] - 1 == arr[x][y] && chk[direct][x][y] == 0){ // 높은 곳으로 가야하는 경우
        if(stair == 1){
            chk[direct][x][y] = 1; // 경사로 표시
            dfs(x+dx[direct], y+dy[direct], direct, stair);
        }
        else{
            int nx = x;
            int ny = y;
            
            for(int i=1; i<stair; i++){
                nx = nx - dx[direct];
                ny = ny - dy[direct];
                
                if(arr[x][y] != arr[nx][ny] || chk[direct][nx][ny] == 1)
                    return;
            }
            
            for(int h=0; h<stair; h++){ // 경사로 설치한 곳 체크
                chk[direct][nx][ny] = 1;
                    
                nx += dx[direct];
                ny += dy[direct];
            }
            
            dfs(nx, ny, direct, stair);
        }
    }
    if(arr[x+dx[direct]][y+dy[direct]] + 1 == arr[x][y] && chk[direct][x+dx[direct]][y+dy[direct]] == 0){ // 낮은 곳으로 가야하는 경우
        if(stair == 1){
            chk[direct][x+dx[direct]][y+dy[direct]] = 1; // 경사로 표시
            dfs(x+dx[direct], y+dy[direct], direct, stair);
        }
        else{
            int nx = x;
            int ny = y;
            
            for(int i=0; i<stair; i++){
                nx = nx + dx[direct];
                ny = ny + dy[direct];
                
                if(arr[x][y]-1 != arr[nx][ny] || chk[direct][nx][ny] == 1)
                    return;
            }
            
            nx = x;
            ny = y;
            
            for(int i=0; i<stair; i++){
                nx = nx + dx[direct];
                ny = ny + dy[direct];
                    
                chk[direct][nx][ny] = 1;
            }
            dfs(nx, ny, direct, stair);
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &N, &L);
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &arr[i][j]);
    
    for(int i=0; i<N; i++){
        dfs(N-1, i, 0, L); // 위로
        dfs(0, i, 1, L); // 아래로
        dfs(i, N-1, 2, L); // 왼쪽으로
        dfs(i, 0, 3, L); // 오른쪽으로
        
        for(int k=0; k<4; k++)
            cnt += ans[k];
        
        if(ans[0] == 1 && ans[1] == 1)
            cnt--;
        if(ans[2] == 1 && ans[3] == 1)
            cnt--;
        
        memset(ans, 0, sizeof(ans));
    }
    
    printf("%d\n", cnt);
    return 0;
}
