// 디저트 카페
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int tc, n, res = -1, cnt, st, en, arr[21][21], visited[21][21], chk[101];

// mode : 0 1 2 3 4 : 우하, (우하 좌하), (좌하 좌상), (좌상 우상), 우상

void func(int x, int y, int mode){
    chk[arr[x][y]] += 1;
    visited[x][y] += 1;
    cnt++;
    
    if(mode == 4 && visited[x][y] == 2){
        if(res < cnt-1)
            res = cnt-1;
    }
    else{
        if(mode == 0){
            if(!chk[arr[x+1][y+1]] && arr[x][y] != 0){
                func(x+1, y+1, 1);
            }
        }
        else if(mode == 1){
            if(!chk[arr[x+1][y+1]] && arr[x+1][y+1] != 0){
                func(x+1, y+1, 1);
            }
            if(!chk[arr[x+1][y-1]] && arr[x+1][y-1] != 0){
                func(x+1, y-1, 2);
            }
        }
        else if(mode == 2){
            if(!chk[arr[x+1][y-1]] && arr[x+1][y-1] != 0){
                func(x+1, y-1, 2);
            }
            if(!chk[arr[x-1][y-1]] && arr[x-1][y-1] != 0){
                func(x-1, y-1, 3);
            }
        }
        else if(mode == 3){
            if(!chk[arr[x-1][y-1]] && arr[x-1][y-1] != 0){
                func(x-1, y-1, 3);
            }
            if(st == x-1 && en == y+1){
                func(x-1, y+1, 4);
            }
            else{
                if(!chk[arr[x-1][y+1]] && arr[x-1][y+1] != 0){
                    func(x-1, y+1, 4);
                }
            }
        }
        else{
            if(st == x-1 && en == y+1){
                func(x-1, y+1, 4);
            }
            else{
                if(!chk[arr[x-1][y+1]] && arr[x-1][y+1] != 0){
                    func(x-1, y+1, 4);
                }
            }
        }
    }
    
    chk[arr[x][y]] -= 1;
    visited[x][y] -= 1;
    cnt--;
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        scanf("%d", &n);
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%d", &arr[i][j]);
        
        for(int i=1; i<n; i++){
            for(int j=2; j<n; j++){
                if((i == 0 && j == n-1) || (i == n-1 && j == 0) || (i == 0 && j == 0) || (i == n-1 && j == n-1))
                    continue;
                else{
                    st = i; en = j;
                    func(i, j, 0);
                    
                    memset(chk, 0, sizeof(chk));
                    memset(visited, 0, sizeof(visited));
                }
            }
        }
        
        printf("#%d %d\n", h+1, res);
        res = -1;
    }
    
    return 0;
}
