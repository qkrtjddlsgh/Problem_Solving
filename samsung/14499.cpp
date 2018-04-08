// 주사위 굴리기
#include <iostream>
using namespace std;

int n, m, x, y, k, tmp, arr[21][21], mov[1001], dice[4][3];
pair <int,int> cur;

// 동서북남 : 1234
// 바닥은 dice[3][1] 윗면은 dice[1][1]

void func(int dir, int x, int y){
    if(dir == 1){ // 동
        cur.first = x;
        cur.second = y + 1;
        
        if(cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= m){
            cur.first = x;
            cur.second = y;
            return;
        }
        
        int tmp1 = dice[1][0]; // 4
        int tmp2 = dice[1][2]; // 3
        
        dice[1][0] = dice[3][1]; // 6
        dice[1][2] = dice[1][1]; // 1
        
        dice[3][1] = tmp2;
        dice[1][1] = tmp1;
    }
    else if(dir == 2){ // 서
        cur.first = x;
        cur.second = y - 1;
        
        if(cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= m){
            cur.first = x;
            cur.second = y;
            return;
        }
        
        int tmp1 = dice[1][0]; // 4
        int tmp2 = dice[1][2]; // 3
        
        dice[1][0] = dice[1][1]; // 1
        dice[1][2] = dice[3][1]; // 6
        
        dice[3][1] = tmp1;
        dice[1][1] = tmp2;
    }
    else if(dir == 3){ // 북
        cur.first = x - 1;
        cur.second = y;
        
        if(cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= m){
            cur.first = x;
            cur.second = y;
            return;
        }
        
        int tmp1 = dice[0][1];
        int tmp2 = dice[1][1];
        int tmp3 = dice[2][1];
        int tmp4 = dice[3][1];
        
        dice[0][1] = tmp2;
        dice[1][1] = tmp3;
        dice[2][1] = tmp4;
        dice[3][1] = tmp1;
    }
    else if(dir == 4){ // 남
        cur.first = x + 1;
        cur.second = y;
        
        if(cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= m){
            cur.first = x;
            cur.second = y;
            return;
        }
        
        int tmp1 = dice[0][1];
        int tmp2 = dice[1][1];
        int tmp3 = dice[2][1];
        int tmp4 = dice[3][1];
        
        dice[0][1] = tmp4;
        dice[1][1] = tmp1;
        dice[2][1] = tmp2;
        dice[3][1] = tmp3;
    }
    
    if(arr[cur.first][cur.second] == 0){
        arr[cur.first][cur.second] = dice[3][1];
    }
    else{
        dice[3][1] = arr[cur.first][cur.second];
        arr[cur.first][cur.second] = 0;
    }
    
    printf("%d\n", dice[1][1]);
}

int main(int argc, char *argv[]){
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);
    
    for(int i=0; i<k; i++)
        scanf("%d", &mov[i]);
    
    cur.first = x;
    cur.second = y;
    
    for(int i=0; i<k; i++)
        func(mov[i], cur.first, cur.second);
    
    return 0;
}
