// 토마토
#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int x, y, cnt;
int state, tmax;

int visit[101][101][101];
int input[101][101][101];

int dx[7] = {-1, 1, 0, 0, 0, 0};
int dy[7] = {0, 0, -1, 1, 0, 0};
int dz[7] = {0, 0, 0, 0, -1, 1};

queue <pair<int, pair<int, int>>> q;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();
        
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < 100 && ny < 100 && nz < 100 && input[nx][ny][nz] == 0){
                input[nx][ny][nz] = 1;
                q.push({nx, {ny, nz}});
                visit[nx][ny][nz] = visit[x][y][z] + 1;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &m, &n);
    scanf("%d", &h);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<h; k++){
                scanf("%1d", &input[i][j][k]);
                if(input[i][j][k] == 1){
                    q.push({i, {j, k}});
                    visit[i][j][k] = 1;
                }
                if(input[i][j][k] == 1 && state == 0)
                    state = 0;
                else state = 1;
            }
        }
    }
    
    
    if(!state)
        printf("%d\n", state);
    else{
        bfs();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<h; j++){
                    if(input[i][j][k] != 1){
                        state = -1;
                        printf("%d\n", state);
                        return 0;
                    }
                    else{
                        tmax = max(visit[i][j][k], tmax);
                    }
                }
            }
        }
        
        if(state)
            printf("%d\n", tmax);
    }
    
    return 0;
}
