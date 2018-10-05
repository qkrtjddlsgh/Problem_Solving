// 뱀 : 재귀가 아닌 리턴
#include <iostream>
#include <queue>
using namespace std;

int n, k, l, ans, arr[101][101];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char snake[10001];
queue <pair<int,int>> body;

void snake_body(int some, int x, int y){
    if(some){
        arr[x][y] = 2;
        
        body.push({x, y});
    }
    else if(!some){
        int bx = body.front().first;
        int by = body.front().second;
        body.pop();
        
        arr[bx][by] = 0;
    }
}

void func(int x, int y, int dir, int cnt){
    if(snake[cnt] == 'D'){
        if(dir == 0)
            dir = 2;
        else if(dir == 1)
            dir = 3;
        else if(dir == 2)
            dir = 1;
        else if(dir == 3)
            dir = 0;
    }
    if(snake[cnt] == 'L'){
        if(dir == 0)
            dir = 3;
        else if(dir == 1)
            dir = 2;
        else if(dir == 2)
            dir = 0;
        else if(dir == 3)
            dir = 1;
    }
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if(nx < 1 || ny < 1 || nx > n || ny > n){
        ans = cnt + 1;
        return;
    }
    
    if(arr[nx][ny] == 1){ // 사과
        snake_body(1, nx, ny);
        
        return func(nx, ny, dir, cnt + 1);
    }
    if(arr[nx][ny] == 0){ // 땅
        snake_body(0, x, y);
        snake_body(1, nx, ny);
        
        return func(nx, ny, dir, cnt + 1);
    }
    if(arr[nx][ny] == 2){ // 뱀
        ans = cnt + 1;
        return;
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
        
        snake[z] = c; // 명령어
    }
    
    body.push({1, 1});
    func(1, 1, 0, 0);
    
    cout << ans << "\n";
    return 0;
}
