// 드래곤 커브 : 규칙 찾기!!
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, x, y, d, g, nx, ny, ans, arr[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector <int> dragon;
stack <int> before;

void curve(int x, int y){
    nx = x;
    ny = y;
    
    arr[x][y] = 1;
    
    for(int i=0; i<dragon.size(); i++){
        nx += dx[dragon[i]];
        ny += dy[dragon[i]];
        
        arr[nx][ny] = 1;
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        
        dragon.push_back(d);
        before.push(d);
        
        for(int j=1; j<=g; j++){
            while(!before.empty()){
                int cur = before.top();
                before.pop();
                
                if(cur == 0){
                    dragon.push_back(1);
                }
                if(cur == 1){
                    dragon.push_back(2);
                }
                if(cur == 2){
                    dragon.push_back(3);
                }
                if(cur == 3){
                    dragon.push_back(0);
                }
            }
            
            for(int k=0; k<dragon.size(); k++){
                before.push(dragon[k]);
            }
        }
        
        curve(x, y);
        
        while(!before.empty())
            before.pop();
        
        dragon.clear();
    }
    
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1])
                ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
