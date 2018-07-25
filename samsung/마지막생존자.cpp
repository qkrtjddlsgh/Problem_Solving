// 마지막생존자
#include <iostream>
#include <cstring>
using namespace std;

int tc, n, ans, arr[11][11]; // 0 : 불모지

int dx[] = {-1,1,0,0,1,-1,1,-1};
int dy[] = {0,0,-1,1,-1,1,1,-1};

void func(int x, int y){
    int water = 0, mountain = 0, grass = 0;
    
    if(arr[x][y] == 1){
        water = 1;
    }
    if(arr[x][y] == 2){
        mountain = 1;
    }
    if(arr[x][y] == 3){
        grass = 1;
    }
    
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 0){
            return;
        }
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 1){
            water = 1;
        }
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 2){
            mountain = 1;
        }
        if(nx >= 0 && ny >= 0 && nx < n && ny < n && arr[nx][ny] == 3){
            grass = 1;
        }
    }
    
    if(water && mountain && grass){
        ans++;
    }
    else
        return;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int i=0; i<tc; i++){
        cin >> n;
        
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin >> arr[j][k];
            }
        }
        
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(arr[j][k] == 0)
                    continue;
                else
                    func(j, k);
            }
        }
        
        cout << "#" << i+1 << " " << ans << "\n";
        
        memset(arr, 0, sizeof(arr));
        ans = 0;
    }
    
    return 0;
}
