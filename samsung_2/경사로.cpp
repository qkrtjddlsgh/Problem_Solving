// 경사로 : 오타 조심!!
#include <iostream>
#include <cstring>
using namespace std;

int n, l, cnt, ans[4], arr[101][101], chk[4][101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void func(int x, int y, int dir){
    if((dir == 0 && x == 0) || (dir == 1 && x == n-1) || (dir == 2 && y == 0) || (dir == 3 && y == n-1)){
        ans[dir] = 1;
        return;
    }
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if(arr[x][y] == arr[nx][ny]){
        func(nx, ny, dir);
    }
    else if(arr[x][y] + 1 == arr[nx][ny] && !chk[dir][x][y]){ // 높은곳
        if(l == 1){
            chk[dir][x][y] = 1;
            func(nx, ny, dir);
        }
        else{
            nx = x;
            ny = y;
            
            for(int i=1; i<l; i++){
                nx -= dx[dir];
                ny -= dy[dir];
                
                if(arr[x][y] != arr[nx][ny] || chk[dir][nx][ny])
                    return;
            }
            
            for(int i=0; i<l; i++){
                chk[dir][nx][ny] = 1;
                
                nx += dx[dir];
                ny += dy[dir];
            }
            
            func(nx, ny, dir);
        }
    }
    else if(arr[x][y] - 1 == arr[nx][ny] && !chk[dir][nx][ny]){ // 낮은곳
        if(l == 1){
            chk[dir][nx][ny] = 1;
            func(nx, ny, dir);
        }
        else{
            nx = x;
            ny = y;
            
            for(int i=0; i<l; i++){
                nx += dx[dir];
                ny += dy[dir];
                
                if(arr[x][y] - 1 != arr[nx][ny] || chk[dir][nx][ny])
                    return;
            }
            
            nx = x;
            ny = y;
            
            for(int i=0; i<l; i++){
                nx += dx[dir];
                ny += dy[dir];
                
                chk[dir][nx][ny] = 1;
            }
            
            func(nx, ny, dir);
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> l;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        func(n-1, i, 0);
        func(0, i, 1);
        func(i, n-1, 2);
        func(i, 0, 3);
        
        for(int j=0; j<4; j++)
            cnt += ans[j];
        
        if(ans[0] == 1 && ans[1] == 1)
            cnt--;
        if(ans[2] == 1 && ans[3] == 1)
            cnt--;
        
        memset(ans, 0, sizeof(ans));
    }
    
    cout << cnt << "\n";
    return 0;
}
