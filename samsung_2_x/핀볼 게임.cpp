// 핀볼 게임
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int tc, n, nx, ny, maxVal, ans, chk, startx, starty, arr[101][101];

vector <pair<int,pair<int,int>>> start;
vector <pair<int,pair<int,int>>> hole;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void func(int x, int y, int cnt, int dir){
    if(chk)
        return;
    
    nx = x + dx[dir];
    ny = y + dy[dir];
    
    if(nx < -1 || ny < -1 || nx > n || ny > n)
        return;
    if(startx == nx && starty == ny && cnt > 0){
        chk = 1;
        maxVal = cnt;
        return;
    }
    if(arr[nx][ny] == -1){
        chk = 1;
        maxVal = cnt;
        return;
    }
    
    if(nx == -1 || ny == -1 || nx == n || ny == n){
        if(dir == 0)
            func(x, y, cnt + 1, 1);
        else if(dir == 1)
            func(x, y, cnt + 1, 0);
        else if(dir == 2)
            func(x, y, cnt + 1, 3);
        else if(dir == 3)
            func(x, y, cnt + 1, 2);
    }
    
    if(arr[nx][ny] == 0)
        func(nx, ny, cnt, dir);
    else{
        if(dir == 0){ // 동
            if(arr[nx][ny] == 1){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 1);
            }
            else if(arr[nx][ny] == 2){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 1);
            }
            else if(arr[nx][ny] == 3){
                func(nx, ny, cnt + 1, 2);
            }
            else if(arr[nx][ny] == 4){
                func(nx, ny, cnt + 1, 3);
            }
            else if(arr[nx][ny] == 5){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 1);
            }
            else if(arr[nx][ny] >= 6){
                for(int i=0; i<hole.size(); i++){
                    if(hole[i].first == arr[nx][ny] && hole[i].second.first != nx && hole[i].second.second != ny){
                        func(hole[i].second.first, hole[i].second.second, cnt, dir);
                        break;
                    }
                }
            }
        }
        else if(dir == 1){ // 서
            if(arr[nx][ny] == 1){
                func(nx, ny, cnt + 1, 3);
            }
            else if(arr[nx][ny] == 2){
                func(nx, ny, cnt + 1, 2);
            }
            else if(arr[nx][ny] == 3){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 0);
            }
            else if(arr[nx][ny] == 4){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 0);
            }
            else if(arr[nx][ny] == 5){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 0);
            }
            else if(arr[nx][ny] >= 6){
                for(int i=0; i<hole.size(); i++){
                    if(hole[i].first == arr[nx][ny] && hole[i].second.first != nx && hole[i].second.second != ny){
                        func(hole[i].second.first, hole[i].second.second, cnt, dir);
                        break;
                    }
                }
            }
        }
        else if(dir == 2){ // 남
            if(arr[nx][ny] == 1){
                func(nx, ny, cnt + 1, 0);
            }
            else if(arr[nx][ny] == 2){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 3);
            }
            else if(arr[nx][ny] == 3){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 3);
            }
            else if(arr[nx][ny] == 4){
                func(nx, ny, cnt + 1, 1);
            }
            else if(arr[nx][ny] == 5){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 3);
            }
            else if(arr[nx][ny] >= 6){
                for(int i=0; i<hole.size(); i++){
                    if(hole[i].first == arr[nx][ny] && hole[i].second.first != nx && hole[i].second.second != ny){
                        func(hole[i].second.first, hole[i].second.second, cnt, dir);
                        break;
                    }
                }
            }
        }
        else if(dir == 3){ // 북
            if(arr[nx][ny] == 1){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 2);
            }
            else if(arr[nx][ny] == 2){
                func(nx, ny, cnt + 1, 0);
            }
            else if(arr[nx][ny] == 3){
                func(nx, ny, cnt + 1, 1);
            }
            else if(arr[nx][ny] == 4){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 2);
            }
            else if(arr[nx][ny] == 5){
                nx = x - dx[dir];
                ny = y - dy[dir];
                
                func(nx, ny, cnt + 1, 2);
            }
            else if(arr[nx][ny] >= 6){
                for(int i=0; i<hole.size(); i++){
                    if(hole[i].first == arr[nx][ny] && hole[i].second.first != nx && hole[i].second.second != ny){
                        func(hole[i].second.first, hole[i].second.second, cnt, dir);
                        break;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                
                if(arr[i][j] >= 6 && arr[i][j] <= 10)
                    hole.push_back({arr[i][j], {i, j}});
                if(arr[i][j] == 0){
                    for(int a=0; a<4; a++){
                        start.push_back({a, {i, j}});
                    }
                }
            }
        }
        
        for(int i=0; i<start.size(); i++){
            startx = start[i].second.first;
            starty = start[i].second.second;
            chk = 0;
            
            func(start[i].second.first, start[i].second.second, 0, start[i].first);
            
            ans = max(ans, maxVal);
            maxVal = 0;
        }
        
        cout << "#" << t << " " << ans << "\n";
        
        start.clear(); hole.clear();
        memset(arr, 0, sizeof(arr));
        maxVal = 0; ans = 0;
    }
    
    return 0;
}
