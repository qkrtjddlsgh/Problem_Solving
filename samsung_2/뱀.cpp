// 뱀
#include <iostream>
#include <queue>
using namespace std;

int n, k, l, ans, arr[101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

queue <pair<int,char>> snake;

void func(int x, int y, int dir, int len, int cnt){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if(nx < 1 || ny < 1 || nx >= n + 1 || ny >= n + 1)
        return;
    
    if(dir == 0){
        if(arr[nx][ny]){
            func(nx, ny, dir, len + 1, cnt + 1);
        }
        else
            func(nx, ny, dir, len, cnt + 1);
    }
    else if(dir == 1){
        if(arr[nx][ny]){
            func(nx, ny, dir, len + 1, cnt + 1);
        }
        else
            func(nx, ny, dir, len, cnt + 1);
    }
    else if(dir == 2){
        if(arr[nx][ny]){
            func(nx, ny, dir, len + 1, cnt + 1);
        }
        else
            func(nx, ny, dir, len, cnt + 1);
    }
    else if(dir == 3){
        if(arr[nx][ny]){
            func(nx, ny, dir, len + 1, cnt + 1);
        }
        else
            func(nx, ny, dir, len, cnt + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        
        arr[x][y] = 1; // 사과 위치
    }
    
    cin >> l;
    
    for(int i=0; i<l; i++){
        int z; char c;
        cin >> z >> c;
        
        snake.push({z, c}); // 명령어
    }
    
    // dir {0, 1, 2, 3} : {동, 서, 남, 북}
    func(1, 1, 0, 1, 0);
    
    return 0;
}

/*
 
 6
 3
 3 4
 2 5
 5 3
 3
 3 D (3초후 오른쪽으로 90도)
 15 L (15초후 왼쪽으로 90도)
 17 D (17초후 오른쪽으로 90도)
 
 0 0 0 0 0 0
 0 0 0 0 1 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 1 2 0 0
 0 0 0 2 0 0
 
 */
