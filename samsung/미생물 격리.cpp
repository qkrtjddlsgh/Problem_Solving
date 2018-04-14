// 미생물 격리
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int tc, n, m, k, ans, map[101][101];

struct bugs {
    int r;
    int c;
    int num;
    int dir;
};

struct bugs arr[1001];

// 상하좌우 : 1234

void func(){
    for(int i=0; i<k; i++){
        int x = arr[i].r;
        int y = arr[i].c;
        
        if(x == -1 && y == -1)
            continue;
        
        if(arr[i].dir == 1){
            if(x-1 >= 0 && y >= 0 && x-1 < n && y < n && map[x-1][y] != 2){
                arr[i].r = x-1;
                arr[i].c = y;
            }
            else if(x-1 >= 0 && y >= 0 && x-1 < n && y < n && map[x-1][y] == 2){
                arr[i].r = x-1;
                arr[i].c = y;
                arr[i].dir = 2;
            }
        }
        else if(arr[i].dir == 2){
            if(x+1 >= 0 && y >= 0 && x+1 < n && y < n && map[x+1][y] != 2){
                arr[i].r = x+1;
                arr[i].c = y;
            }
            else if(x+1 >= 0 && y >= 0 && x+1 < n && y < n && map[x+1][y] == 2){
                arr[i].r = x+1;
                arr[i].c = y;
                arr[i].dir = 1;
            }
        }
        else if(arr[i].dir == 3){
            if(x >= 0 && y-1 >= 0 && x < n && y-1 < n && map[x][y-1] != 2){
                arr[i].r = x;
                arr[i].c = y-1;
            }
            else if(x >= 0 && y-1 >= 0 && x < n && y-1 < n && map[x][y-1] == 2){
                arr[i].r = x;
                arr[i].c = y-1;
                arr[i].dir = 4;
            }
        }
        else if(arr[i].dir == 4){
            if(x >= 0 && y+1 >= 0 && x < n && y+1 < n && map[x][y+1] != 2){
                arr[i].r = x;
                arr[i].c = y+1;
            }
            else if(x >= 0 && y+1 >= 0 && x < n && y+1 < n && map[x][y+1] == 2){
                arr[i].r = x;
                arr[i].c = y+1;
                arr[i].dir = 3;
            }
        }
    }
}

void cal(){
    int bindex = 0 ;
    
    if(map[arr[0].r][arr[0].c] == 2 && arr[0].r != -1){
        arr[0].num /= 2;
    }
    
    for(int i=1; i<k; i++){
        if(arr[i].r == -1 && arr[i].c == -1){
            bindex++;
            continue;
        }
        if(arr[i].r == arr[bindex].r && arr[i].c == arr[bindex].c){
            arr[i].num += arr[bindex].num;
            
            arr[bindex].r = -1;
            arr[bindex].c = -1;
            arr[bindex].num = -1;
            arr[bindex].dir = -1;
        }
        
        bindex++;
    
        if(map[arr[i].r][arr[i].c] == 2 && arr[i].num != -1){
            arr[i].num /= 2;
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        scanf("%d %d %d", &n, &m, &k);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0 || i == n-1 || j == n-1)
                    map[i][j] = 2; // 벽
            }
        }
        
        memset(arr, 0, sizeof(arr));
        
        for(int i=0; i<k; i++)
            scanf("%d %d %d %d", &arr[i].r, &arr[i].c, &arr[i].num, &arr[i].dir);
        
        while(m--){
            func();
            
            sort(arr, arr+k, [](const struct bugs &a, const struct bugs &b){
                if(a.r == b.r && a.c == b.c){
                    return a.num < b.num;
                }
                if(a.r == b.r){
                    return a.c < b.c;
                }
                return a.r < b.r;
            });
            
            cal();
        }
        
        for(int i=0; i<k; i++){
            if(arr[i].num == -1)
                continue;
            ans += arr[i].num;
        }
        
        printf("#%d %d\n", h+1, ans);
        
        memset(arr, 0, sizeof(arr));
        memset(map, 0, sizeof(map));
        ans = 0;
    }
    
    return 0;
}
