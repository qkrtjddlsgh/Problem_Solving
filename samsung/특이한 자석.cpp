// 특이한 자석
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int tc, k, ans, ndir, arr[9][9], temp1, temp2;
queue <pair<int,int>> q; // 자석 번호, 방향 (1 : 시계, -1 : 반시계)

void change(int num, int direct){
    int temp = 0;
    
    if(direct == 1){
        temp = arr[num][8];
        
        for(int i=8; i>=2; i--)
            arr[num][i] = arr[num][i-1];
        
        arr[num][1] = temp;
    }
    else{
        temp = arr[num][1];
        
        for(int i=1; i<=7; i++)
            arr[num][i] = arr[num][i+1];
        
        arr[num][8] = temp;
    }
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int c=0; c<tc; c++){
        scanf("%d", &k); // 자석을 회전시키는 횟수
        
        for(int i=1; i<=4; i++)
            for(int j=1; j<=8; j++)
                // 1 : s, 0 : n
                scanf("%d", &arr[i][j]);
        
        for(int i=0; i<k; i++){
            scanf("%d %d", &temp1, &temp2);
            q.push({temp1, temp2});
        }
        
        while(!q.empty()){
            int cur = q.front().first;
            int dir = q.front().second;
            q.pop();
            
            if(dir == 1)
                ndir = -1;
            else if(dir == -1)
                ndir = 1;
            
            queue <pair<int,int>> tmp;
            tmp.push({cur, dir});
            
            if(cur == 1){
                for(int i=1; i<=3; i++){
                    int cdir = 0;
                    
                    if((i+1)%2 == cur%2)
                        cdir = dir;
                    else
                        cdir = ndir;
                    
                    if(arr[i][3] != arr[i+1][7]){
                        tmp.push({i+1, cdir});
                    }
                    else
                        break;
                }
            }
            else if(cur == 2){
                if(arr[2][3] != arr[3][7]){
                    tmp.push({3, ndir});
                    
                    if(arr[3][3] != arr[4][7])
                        tmp.push({4, dir});
                }
                if(arr[2][7] != arr[1][3]){
                    tmp.push({1, ndir});
                }
            }
            else if(cur == 3){
                if(arr[3][3] != arr[4][7]){
                    tmp.push({4, ndir});
                }
                if(arr[3][7] != arr[2][3]){
                    tmp.push({2, ndir});
                    
                    if(arr[2][7] != arr[1][3])
                        tmp.push({1, dir});
                }
            }
            else if(cur == 4){
                for(int i=3; i>=1; i--){
                    int cdir = 0;
                    
                    if(i%2 == cur%2)
                        cdir = dir;
                    else
                        cdir = ndir;
                    
                    if(arr[i][3] != arr[i+1][7]){
                        tmp.push({i, cdir});
                    }
                    else
                        break;
                }
            }
            
            while(!tmp.empty()){
                int a = tmp.front().first;
                int b = tmp.front().second;
                tmp.pop();
                
                change(a, b);
            }
        }
        
        for(int i=1; i<=4; i++){
            if(arr[i][1] == 1)
                ans += pow(2, i-1);
        }
        
        printf("#%d %d\n", c+1, ans);
        
        memset(arr, 0, sizeof(arr));
        ans = 0;
    }
    
    return 0;
}
