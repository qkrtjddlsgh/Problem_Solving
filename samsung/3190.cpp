// 뱀
#include <iostream>
#include <queue>
using namespace std;

int n, k, x, y, l, t, ans = -1, visited[101][101], arr[101][101]; char tmp, c[10001];

queue <pair<int,int>> q;

// 상하좌우 : 0123 : 3201
// 상하좌우 : 0123 : 2310

void func(int x, int y, int direct){
    visited[x][y] = 1;
    ans++;
    
    //cout << x << " " << y << endl;
    
    if(c[ans] == 'L'){
        if(direct == 0)
            direct = 2;
        else if(direct == 1)
            direct = 3;
        else if(direct == 2)
            direct = 1;
        else
            direct = 0;
    }
    if(c[ans] == 'D'){
        if(direct == 0)
            direct = 3;
        else if(direct == 1)
            direct = 2;
        else if(direct == 2)
            direct = 0;
        else
            direct = 1;
    }
    
    if(x < 0 || y < 0 || x >= n || y >= n)
        return;
    
    if(direct == 0){
        if(x-1 < 0 || y < 0 || x-1 >= n || y >= n || visited[x-1][y]){
            return;
        }
        if(arr[x-1][y] == 1){ // 사과가 있는 경우
            arr[x-1][y] = 0;
            q.push({x-1, y});
            func(x-1, y, 0);
        }
        else{ // 없는 경우
            int nx = q.front().first;
            int ny = q.front().second;
            visited[nx][ny] = 0;
            q.pop();
            
            q.push({x-1, y});
            func(x-1, y, 0);
        }
    }
    else if(direct == 1){
        if(x+1 < 0 || y < 0 || x+1 >= n || y >= n || visited[x+1][y]){
            return;
        }
        if(arr[x+1][y] == 1){ // 사과가 있는 경우
            arr[x+1][y] = 0;
            q.push({x+1, y});
            func(x+1, y, 1);
        }
        else{ // 없는 경우
            int nx = q.front().first;
            int ny = q.front().second;
            visited[nx][ny] = 0;
            q.pop();
            
            q.push({x+1, y});
            func(x+1, y, 1);
        }
    }
    else if(direct == 2){
        if(x < 0 || y-1 < 0 || x >= n || y-1 >= n || visited[x][y-1]){
            return;
        }
        if(arr[x][y-1] == 1){ // 사과가 있는 경우
            arr[x][y-1] = 0;
            q.push({x, y-1});
            func(x, y-1, 2);
        }
        else{ // 없는 경우
            int nx = q.front().first;
            int ny = q.front().second;
            visited[nx][ny] = 0;
            q.pop();
            
            q.push({x, y-1});
            func(x, y-1, 2);
        }
    }
    else if(direct == 3){
        if(x < 0 || y+1 < 0 || x >= n || y+1 >= n || visited[x][y+1]){
            return;
        }
        if(arr[x][y+1] == 1){ // 사과가 있는 경우
            arr[x][y+1] = 0;
            q.push({x, y+1});
            func(x, y+1, 3);
        }
        else{ // 없는 경우
            int nx = q.front().first;
            int ny = q.front().second;
            visited[nx][ny] = 0;
            q.pop();
            
            q.push({x, y+1});
            func(x, y+1, 3);
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &k);
    
    for(int i=0; i<k; i++){
        scanf("%d %d", &x, &y);
        arr[x-1][y-1] = 1;
    }
    
    scanf("%d", &l);
    
    for(int i=0; i<l; i++){
        scanf("%d %c", &t, &tmp);
        c[t] = tmp;
    }
    
    q.push({0, 0});
    func(0, 0, 3);
    
    printf("%d\n", ans + 1);
    return 0;
}
