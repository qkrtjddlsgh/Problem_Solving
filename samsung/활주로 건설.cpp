// 활주로 건설
#include <iostream>
#include <cstring>
using namespace std;

int tc, N, X, cnt, arr[21][21], chk[4][21][21], ans[4];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

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
    scanf("%d", &tc);
    
    for(int i=1; i<=tc; i++){
        scanf("%d %d", &N, &X);
        
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                scanf("%d", &arr[j][k]);
        
        for(int h=0; h<N; h++){
            dfs(N-1, h, 0, X); // 위
            dfs(h, N-1, 2, X); // 왼쪽
            
            for(int g=0; g<4; g++)
                cnt += ans[g];
            
            memset(ans, 0, sizeof(ans));
        }
        
        printf("#%d %d\n", i, cnt);

        memset(arr, 0, sizeof(arr));
        memset(chk, 0, sizeof(chk));
        cnt = 0;
    }
    
    return 0;
}
