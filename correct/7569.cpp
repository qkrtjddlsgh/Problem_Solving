// 토마토
#include <bits/stdc++.h>
using namespace std;

int m, n, h, maxval, input[101][101][101];

int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

queue <pair<pair<int,int>,int>> tomato;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> m >> n >> h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> input[i][j][k];
                
                if(input[i][j][k] == 1)
                    tomato.push({{i, j}, k});
            }
        }
    }
    
    while(!tomato.empty()){
        int x = tomato.front().first.first;
        int y = tomato.front().first.second;
        int z = tomato.front().second;
        tomato.pop();
        
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            
            if(nx >= 0 && ny >= 0 && nz >= 0 && nx < h && ny < n && nz < m && input[nx][ny][nz] == 0){
                input[nx][ny][nz] = input[x][y][z] + 1;
                tomato.push({{nx, ny}, nz});
                
                maxval = max(maxval, input[nx][ny][nz]);
            }
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(input[i][j][k] == 0)
                    maxval = 0;
            }
        }
    }
    
    cout << maxval - 1 << "\n";
    return 0;
}
