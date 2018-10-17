// 벽돌 깨기
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int tc, n, w, h, nx, ny, chk, ans = 987654321, cnt, dx[4], dy[4], visited[16], arr[16][16], map[16][16];

void remain(){
    stack <int> sero;
    
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(map[j][i] != 0){
                sero.push(map[j][i]);
                map[j][i] = 0;
            }
        }
        
        int idx = h-1;
        
        while(!sero.empty()){
            int here = sero.top();
            sero.pop();
            
            map[idx][i] = here;
            idx--;
        }
    }
}

void crack(int pos){
    queue <pair<int,pair<int,int>>> q;
    
    for(int i=0; i<h; i++){
        if(map[i][pos] != 0){
            q.push({map[i][pos], {i, pos}});
            break;
        }
    }
    
    while(!q.empty()){
        int wall = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        
        map[x][y] = 0;
        q.pop();
        
        for(int i=1; i<wall; i++){
            nx = x; ny = y;
            
            dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
            dy[0] = 0; dy[1] = 0; dy[2] = -1; dy[3] = 1;
            
            dx[0] *= i; dx[1] *= i; dx[2] *= i; dx[3] *= i;
            dy[0] *= i; dy[1] *= i; dy[2] *= i; dy[3] *= i;
            
            for(int j=0; j<4; j++){
                nx = x + dx[j];
                ny = y + dy[j];
                
                if(nx < 0 || ny < 0 || nx >= h || ny >= w)
                    continue;
                
                if(nx >= 0 && ny >= 0 && nx < h && ny < w && map[nx][ny] == 1)
                    map[nx][ny] = 0;
                if(nx >= 0 && ny >= 0 && nx < h && ny < w && map[nx][ny] != 0)
                    q.push({map[nx][ny], {nx, ny}});
            }
        }
    }
}

void func(int cur){
    if(chk)
        return;
    if(cur == n){
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                map[i][j] = arr[i][j];
        
        for(int i=0; i<n; i++){
            crack(visited[i]);
            remain();
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] != 0)
                    cnt++;
            }
        }
        
        ans = min(ans, cnt);
        cnt = 0;
        
        if(ans == 0)
            chk = 1;
        
        return;
    }
    
    for(int i=0; i<w; i++){
        visited[cur] = i;
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> n >> w >> h;
        
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
                cin >> arr[i][j];
        
        func(0);
        
        cout << "#" << t << " " << ans << "\n";
        
        memset(arr, 0, sizeof(arr));
        memset(map, 0, sizeof(arr));
        ans = 987654321; chk = 0;
    }
    
    return 0;
}

