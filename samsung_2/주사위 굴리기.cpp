// 주사위 굴리기 : 단순 구현
#include <iostream>
using namespace std;

int n, m, x, y, k, nx, ny, command, arr[21][21], dice[4][3];

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void change(int dir){
    if(dir == 1){
        int temp1 = dice[1][0];
        int temp2 = dice[1][1];
        int temp3 = dice[1][2];
        int temp4 = dice[3][1];
        
        dice[1][0] = temp4;
        dice[1][1] = temp1;
        dice[1][2] = temp2;
        dice[3][1] = temp3;
    }
    else if(dir == 2){
        int temp1 = dice[1][0];
        int temp2 = dice[1][1];
        int temp3 = dice[1][2];
        int temp4 = dice[3][1];
        
        dice[1][0] = temp2;
        dice[1][1] = temp3;
        dice[1][2] = temp4;
        dice[3][1] = temp1;
    }
    else if(dir == 3){
        int temp1 = dice[0][1];
        int temp2 = dice[1][1];
        int temp3 = dice[2][1];
        int temp4 = dice[3][1];
        
        dice[0][1] = temp2;
        dice[1][1] = temp3;
        dice[2][1] = temp4;
        dice[3][1] = temp1;
    }
    else if(dir == 4){
        int temp1 = dice[0][1];
        int temp2 = dice[1][1];
        int temp3 = dice[2][1];
        int temp4 = dice[3][1];
        
        dice[0][1] = temp4;
        dice[1][1] = temp1;
        dice[2][1] = temp2;
        dice[3][1] = temp3;
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y >> k;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    nx = x;
    ny = y;
    
    for(int i=0; i<k; i++){
        cin >> command;
        
        nx += dx[command];
        ny += dy[command];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= m){
            nx -= dx[command];
            ny -= dy[command];
            continue;
        }
        else{
            change(command);
            
            if(arr[nx][ny] == 0){
                arr[nx][ny] = dice[3][1];
            }
            else{
                dice[3][1] = arr[nx][ny];
                arr[nx][ny] = 0;
            }
        }
        
        cout << dice[1][1] << "\n";
    }
    
    return 0;
}
