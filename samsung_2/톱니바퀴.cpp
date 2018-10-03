// 톱니바퀴 : 계산을 잘하자!!
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int x, y, k, ans, arr[4][8];

queue <pair<int,int>> command;
queue <pair<int,int>> turns;

void rotate_right(int num){
    int temp = arr[num][7];
    
    for(int i=7; i>0; i--){
        arr[num][i] = arr[num][i-1];
    }
    
    arr[num][0] = temp;
}

void rotate_left(int num){
    int temp = arr[num][0];
    
    for(int i=0; i<7; i++){
        arr[num][i] = arr[num][i+1];
    }
    
    arr[num][7] = temp;
}

int main(int argc, char *argv[]){
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    cin >> k;
    
    for(int i=0; i<k; i++){
        cin >> x >> y;
        command.push({x-1, y});
    }
    
    while(!command.empty()){
        x = command.front().first;
        y = command.front().second;
        command.pop();
        
        if(x == 0){
            turns.push({0, y});
            
            if(arr[0][2] != arr[1][6]){
                turns.push({1, -y});
                
                if(arr[1][2] != arr[2][6]){
                    turns.push({2, y});
                    
                    if(arr[2][2] != arr[3][6]){
                        turns.push({3, -y});
                    }
                }
            }
        }
        else if(x == 1){
            turns.push({1, y});
            
            if(arr[0][2] != arr[1][6]){
                turns.push({0, -y});
            }
            if(arr[1][2] != arr[2][6]){
                turns.push({2, -y});
                
                if(arr[2][2] != arr[3][6]){
                    turns.push({3, y});
                }
            }
        }
        else if(x == 2){
            turns.push({2, y});
            
            if(arr[3][6] != arr[2][2]){
                turns.push({3, -y});
            }
            if(arr[2][6] != arr[1][2]){
                turns.push({1, -y});
                
                if(arr[1][6] != arr[0][2]){
                    turns.push({0, y});
                }
            }
        }
        else if(x == 3){
            turns.push({3, y});
            
            if(arr[3][6] != arr[2][2]){
                turns.push({2, -y});
                
                if(arr[2][6] != arr[1][2]){
                    turns.push({1, y});
                    
                    if(arr[1][6] != arr[0][2]){
                        turns.push({0, -y});
                    }
                }
            }
        }
        
        while(!turns.empty()){
            int num = turns.front().first;
            int dir = turns.front().second;
            turns.pop();
            
            if(dir == 1){
                rotate_right(num);
            }
            else{
                rotate_left(num);
            }
        }
    }
    
    for(int i=0; i<4; i++){
        if(arr[i][0] == 1){
            ans += pow(2, i);
        }
    }
    
    cout << ans << "\n";
    return 0;
}
