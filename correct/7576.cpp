// 토마토
#include <bits/stdc++.h>
using namespace std;

int m, n, maxval, input[1001][1001];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

queue <pair<int,int>> tomato;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> input[i][j];
            
            if(input[i][j] == 1)
                tomato.push({i, j}); // 0일차에 익은 토마토 저장
        }
    }
    
    while(!tomato.empty()){
        int x = tomato.front().first;
        int y = tomato.front().second;
        tomato.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(input[nx][ny] == -1)
                continue;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && input[nx][ny] == 0){
                tomato.push({nx, ny});
                input[nx][ny] = input[x][y] + 1;
                
                maxval = max(input[nx][ny], maxval);
            }
            
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(input[i][j] == 0)
                maxval = 0;
        }
    }
    
    cout << maxval - 1 << "\n";
    return 0;
}
