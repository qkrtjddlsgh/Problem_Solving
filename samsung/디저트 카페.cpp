// 디저트 카페
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tc, n, ans = -1, cnt, st, en, arr[21][21], visited[21][21], chk[101];

int dx[] = {-1, 1, -1, 1};
int dy[] = {1, -1, -1, 1};

void func(int x, int y, int start, int end){
    // 다시 자기 자신으로 돌아올때 조건 필요 + 대각선 모양이 사각형을 이루게 해야함.
    if(x == start && y == end && visited[x][y] == 1 && chk[arr[x][y]] == 1){
        for(int i=0; i<101; i++)
            if(chk[i])
                cnt++;
        return;
    }
    
    visited[x][y] = 1;
    chk[arr[x][y]] = 1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0 && chk[arr[nx][ny]] == 0){
            func(nx, ny, st, en);
        }
    }
    
    visited[x][y] = 0;
    chk[arr[x][y]] = 0;
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        scanf("%d", &n);
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &arr[i][j]);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i == 0 && j == n-1) || (i == n-1 && j == 0) || (i == 0 && j == 0) || (i == n-1 && j == n-1))
                    continue;
                else{
                    st = i; en = j;
                    func(i, j, st, en);
                    
                    memset(chk, 0, sizeof(chk));
                    memset(visited, 0, sizeof(visited));
                    
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
        }
        
        printf("#%d %d\n", h+1, ans);
        ans = -1;
    }
    
    return 0;
}
