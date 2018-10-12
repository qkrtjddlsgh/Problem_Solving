// 2048 (Easy) : 다시 풀기!!
#include <iostream>
#include <cstring>
using namespace std;

int n, m, maxVal, ans, visited[31], map[31][31], arr[31][31];

void move(int dir){
    if(dir == 1){ // 상
        for(int i=0; i<n; i++){
            int ax = 0;
            int bx = ax + 1;
            
            while(bx <= n-1){
                // ax가 비어있는 경우
                if(map[bx][i] != 0){
                    if(map[ax][i] == 0){
                        map[ax][i] = map[bx][i];
                        map[bx][i] = 0;
                    }
                    // ax가 비어있지 않은 경우
                    else {
                        // ax와 bx가 같은 경우
                        if (map[ax][i] == map[bx][i]){
                            map[ax][i] = (map[ax][i] << 1);
                            map[bx][i] = 0;
                            ax++;
                        }
                        // ax와 bx가 다른 경우
                        else{
                            // 한칸 차이
                            if(bx - ax == 1){
                                ax++;
                            }
                            // 두칸이상 차이
                            else{
                                ax++;
                                map[ax][i] = map[bx][i];
                                map[bx][i] = 0;
                            }
                        }
                    }
                }
                bx++;
            }
        }
    }
    else if(dir == 2){ // 하
        for(int i=0; i<n; i++){
            int ax = n - 1;
            int bx = ax - 1;
            
            while(bx >= 0){
                if(map[bx][i] != 0){
                    if(map[ax][i] == 0){
                        map[ax][i] = map[bx][i];
                        map[bx][i] = 0;
                    }
                    else{
                        if(map[ax][i] == map[bx][i]){
                            map[ax][i] = (map[ax][i] << 1);
                            map[bx][i] = 0;
                            ax--;
                        }
                        else{
                            if(ax - bx == 1){
                                ax--;
                            }
                            else{
                                ax--;
                                map[ax][i] = map[bx][i];
                                map[bx][i] = 0;
                            }
                        }
                    }
                }
                bx--;
            }
        }
    }
    else if(dir == 3){ // 좌
        for(int i=0; i<n; i++){
            int ax = 0;
            int bx = ax + 1;
            
            while(bx <= n-1){
                if(map[i][bx] != 0){
                    if(map[i][ax] == 0){
                        map[i][ax] = map[i][bx];
                        map[i][bx] = 0;
                    }
                    else {
                        if (map[i][ax] == map[i][bx]){
                            map[i][ax] = (map[i][ax] << 1);
                            map[i][bx] = 0;
                            ax++;
                        }
                        else{
                            if(bx - ax == 1){
                                ax++;
                            }
                            else{
                                ax++;
                                map[i][ax] = map[i][bx];
                                map[i][bx] = 0;
                            }
                        }
                    }
                }
                bx++;
            }
        }
    }
    else if(dir == 4){ // 우
        for(int i=0; i<n; i++){
            int ax = n - 1;
            int bx = ax - 1;
            
            while(bx >= 0){
                if(map[i][bx] != 0){
                    if(map[i][ax] == 0){
                        map[i][ax] = map[i][bx];
                        map[i][bx] = 0;
                    }
                    else {
                        if (map[i][ax] == map[i][bx]){
                            map[i][ax] = (map[i][ax] << 1);
                            map[i][bx] = 0;
                            ax--;
                        }
                        else{
                            if(ax - bx == 1){
                                ax--;
                            }
                            else{
                                ax--;
                                map[i][ax] = map[i][bx];
                                map[i][bx] = 0;
                            }
                        }
                    }
                }
                bx--;
            }
        }
    }
}

void func(int cur){
    if(cur == 5){
        // copy array
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                map[i][j] = arr[i][j];
        
        for(int i=0; i<5; i++)
            move(visited[i]);
        
        maxVal = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                maxVal = max(maxVal, map[i][j]);
        
        ans = max(ans, maxVal);
        return;
    }
    
    for(int i=1; i<=4; i++){
        visited[cur] = i;
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    func(0);
    
    cout << ans << "\n";
    return 0;
}
