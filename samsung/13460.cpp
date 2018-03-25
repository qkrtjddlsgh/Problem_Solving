// 째로탈출 2
#include <bits/stdc++.h>
using namespace std;

int n, m, visited[11][11];
char input[11][11];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

pair<int,int> first_R_pos, first_B_pos, first_O_pos;

void dfs(int x, int y){
    if(x == first_O_pos.first && y == first_O_pos.second){
        cout << "find\n";
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 1 && ny >= 1 && nx < n && ny < m && (input[nx][ny] == '.' || input[nx][ny] == 'O'))
            dfs(nx, ny);
    }
    
    return;
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &input[i][j]);
            
            if(input[i][j] == 'R'){
                first_R_pos.first = i;
                first_R_pos.second = j;
            }
            if(input[i][j] == 'B'){
                first_B_pos.first = i;
                first_B_pos.second = j;
            }
            if(input[i][j] == 'O'){
                first_O_pos.first = i;
                first_O_pos.second = j;
            }
        }
    }
    
    // R에서 0으로 갈수있는지, 방향전환을 몇번하는지, B랑 동시에 나오지않는지
    dfs(first_R_pos.first, first_R_pos.second);
    
    return 0;
}
