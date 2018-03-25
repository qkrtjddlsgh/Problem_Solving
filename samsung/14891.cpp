// 톱니바퀴
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int arr[5][9], k, ans, ndir, cdir, temp1, temp2;

queue <pair<int,int>> q;
queue <pair<int,int>> tmp;

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
    for(int i=1; i<=4; i++)
        for(int j=1; j<=8; j++)
            scanf("%1d", &arr[i][j]);
    
    scanf("%d", &k);
    
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
        else
            ndir = 1;
        
        if(cur == 1){
            tmp.push({1, dir});
            
            for(int i=1; i<=3; i++){
                if((i+1)%2 == cur%2)
                    cdir = dir;
                else
                    cdir = ndir;
                
                if(arr[i][3] != arr[i+1][7])
                    tmp.push({i+1, cdir});
                else
                    break;
            }
        }
        else if(cur == 2){
            tmp.push({2, dir});
            
            if(arr[2][7] != arr[1][3]){
                tmp.push({1, ndir});
            }
            if(arr[2][3] != arr[3][7]){
                tmp.push({3, ndir});
                
                if(arr[3][3] != arr[4][7])
                    tmp.push({4, dir});
            }
        }
        else if(cur == 3){
            tmp.push({3, dir});
            
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
            tmp.push({4, dir});
            
            for(int i=3; i>=1; i--){
                if(i%2 == cur%2)
                    cdir = dir;
                else
                    cdir = ndir;
                
                if(arr[i+1][7] != arr[i][3])
                    tmp.push({i, cdir});
                else
                    break;
            }
        }
        
        while(!tmp.empty()){
            int a = tmp.front().first;
            int b = tmp.front().second;
            tmp.pop();
            
            change(a,b);
        }
    }
    
    for(int i=1; i<=4; i++){
        if(arr[i][1] == 1)
            ans += pow(2, i-1);
    }
    
    printf("%d\n", ans);
    return 0;
}
