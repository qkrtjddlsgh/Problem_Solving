// 감시 : 모든 순서쌍 완전탐색
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans = 987654321, cnt, camera_size, arr[9][9], visited[9][9];

struct info{
    int x;
    int y;
    int dir;
    int type;
};

vector <info> camera;

void go_left(int x, int y){
    for(int i=y-1; i>=0; i--){
        if(visited[x][i] == 0){
            visited[x][i] = 7;
        }
        else if(visited[x][i] == 6)
            break;
    }
}

void go_right(int x, int y){
    for(int i=y+1; i<m; i++){
        if(visited[x][i] == 0){
            visited[x][i] = 7;
        }
        else if(visited[x][i] == 6)
            break;
    }
}

void go_top(int x, int y){
    for(int i=x-1; i>=0; i--){
        if(visited[i][y] == 0){
            visited[i][y] = 7;
        }
        else if(visited[i][y] == 6)
            break;
    }
}

void go_bottom(int x, int y){
    for(int i=x+1; i<n; i++){
        if(visited[i][y] == 0){
            visited[i][y] = 7;
        }
        else if(visited[i][y] == 6)
            break;
    }
}

void dfs(int x, int y, int dir, int type){
    if(type == 1){
        if(dir == 0){
            go_right(x, y);
        }
        else if(dir == 1){
            go_top(x, y);
        }
        else if(dir == 2){
            go_left(x, y);
        }
        else if(dir == 3){
            go_bottom(x, y);
        }
    }
    else if(type == 2){
        if(dir == 0){
            go_left(x, y);
            go_right(x, y);
        }
        else if(dir == 1){
            go_top(x, y);
            go_bottom(x, y);
        }
        else if(dir == 2){
            go_left(x, y);
            go_right(x, y);
        }
        else if(dir == 3){
            go_top(x, y);
            go_bottom(x, y);
        }
    }
    else if(type == 3){
        if(dir == 0){
            go_top(x, y);
            go_right(x, y);
        }
        else if(dir == 1){
            go_left(x, y);
            go_top(x, y);
        }
        else if(dir == 2){
            go_bottom(x, y);
            go_left(x, y);
        }
        else if(dir == 3){
            go_right(x, y);
            go_bottom(x, y);
        }
    }
    else if(type == 4){
        if(dir == 0){
            go_top(x, y);
            go_left(x, y);
            go_right(x, y);
        }
        else if(dir == 1){
            go_top(x, y);
            go_left(x, y);
            go_bottom(x, y);
        }
        else if(dir == 2){
            go_left(x, y);
            go_bottom(x, y);
            go_right(x, y);
        }
        else if(dir == 3){
            go_top(x, y);
            go_bottom(x, y);
            go_right(x, y);
        }
    }
    else if(type == 5){
        go_top(x, y);
        go_left(x, y);
        go_bottom(x, y);
        go_right(x, y);
    }
}

void func(int cur){
    if(cur == camera_size){
        // copy array
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j] = arr[i][j];
            }
        }
        
        // dfs search
        for(int i=0; i<camera.size(); i++){
            dfs(camera[i].x, camera[i].y, camera[i].dir, camera[i].type);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == 0){
                    cnt++;
                }
            }
        }
        
        ans = min(ans, cnt);
        cnt = 0;
        
        return;
    }
    
    camera[cur].dir = 0;
    func(cur + 1);
        
    camera[cur].dir = 1;
    func(cur + 1);
        
    camera[cur].dir = 2;
    func(cur + 1);
        
    camera[cur].dir = 3;
    func(cur + 1);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] > 0 && arr[i][j] < 6){
                camera.push_back({i, j, 0, arr[i][j]}); // cctv 위치
            }
        }
    }
    
    camera_size = (int)camera.size();
    
    func(0);
    
    cout << ans << "\n";
    return 0;
}
