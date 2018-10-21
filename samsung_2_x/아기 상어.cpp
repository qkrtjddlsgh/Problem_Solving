// 아기 상어
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, ans, chk, arr[21][21], visited[21][21];

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, 1, -1, 0};

struct fish{
    int x;
    int y;
    int hp;
    int state;
};

struct fish bok;
vector <fish> go;

void bfs(int x, int y, int hp){
    visited[x][y] = 1;
    
    queue <pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] <= hp){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
                
                if(bok.state < hp - 1 && arr[nx][ny] < hp && arr[nx][ny] != 0){
                    bok.state += 1;
                    ans += visited[nx][ny] - 1;
                    bok.x = nx;
                    arr[nx][ny] = 0;
                    bok.y = ny;
                    chk = 1;
                    break;
                }
                else if(bok.state == hp - 1 && arr[nx][ny] < hp && arr[nx][ny] != 0){
                    bok.state = 0;
                    bok.hp += 1;
                    ans += visited[nx][ny] - 1;
                    bok.x = nx;
                    bok.y = ny;
                    arr[nx][ny] = 0;
                    chk = 1;
                    break;
                }
            }
        }
        if(chk){
            while(!q.empty())
                q.pop();
            chk = 0;
            break;
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 9){
                bok.x = i;
                bok.y = j;
                bok.hp = 2;
                bok.state = 0;
            }
            if(arr[i][j] > 0 && arr[i][j] < 9){
                go.push_back({i, j, arr[i][j], 0});
            }
        }
    }
    
    for(int i=0; i<go.size(); i++){
        memset(visited, 0, sizeof(visited));
        bfs(bok.x, bok.y, bok.hp);
    }
    
    cout << ans << "\n";
    return 0;
}
