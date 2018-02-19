// 소문난 칠공주
#include <bits/stdc++.h>
using namespace std;

int cnt, visited[5][5];
char arr[5][5];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void chk(int x, int y, int lee, int lim, int count){
    if(count == 7 && lee >= 4){
        cnt++;
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && visited[nx][ny] == 0 && arr[nx][ny] == 'S'){
            visited[nx][ny] = 1;
            chk(nx, ny, lee+1, lim, count+1);
            visited[nx][ny] = 0;
        }
        if(nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && visited[nx][ny] == 0 && arr[nx][ny] == 'Y'){
            visited[nx][ny] = 1;
            chk(nx, ny, lee, lim+1, count+1);
            visited[nx][ny] = 0;
        }
    }
    
    return;
}

int main(int argc, char *argv[]){
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            scanf(" %c", &arr[i][j]);
        }
    }
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            memset(visited, 0, sizeof(visited));
            
            if(arr[i][j] == 'S'){
                visited[i][j] = 1;
                chk(i, j, 1, 0, 1);
            }
            else{
                visited[i][j] = 1;
                chk(i, j, 0, 1, 1);
            }
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
