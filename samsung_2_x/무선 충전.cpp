// 무선 충전
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int tc, m, n, x, y, c, p, achk, bchk, sum, maxVal, a[101], b[101], visited[11][101][101]; // 1234 : 상우하좌

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

pair <int,int> A;
pair <int,int> B;

struct AP{
    int x; // x좌표
    int y; // y좌표
    int c; // 충전량
    int p; // 처리량
};

vector <AP> ap;
vector <int> aa;
vector <int> bb;

void bfs(int x, int y, int ap_num, int cnt){
    visited[ap_num][x][y] = 1;
    
    queue <pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nnx = nx + dx[i];
            int nny = ny + dy[i];
            
            if(nnx < 1 || nny < 1 || nnx >= 11 || nny >= 11)
                continue;
            
            if(visited[ap_num][nnx][nny] == 0 && visited[ap_num][nx][ny] <= cnt){
                visited[ap_num][nnx][nny] =  visited[ap_num][nx][ny] + 1;
                q.push({nnx, nny});
            }
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> m >> n;
        
        for(int i=0; i<m; i++)
            cin >> a[i];
        
        for(int i=0; i<m; i++)
            cin >> b[i];
        
        for(int i=0; i<n; i++){
            cin >> y >> x >> c >> p;
            
            ap.push_back({x, y, c, p});
            bfs(ap[i].x, ap[i].y, i, ap[i].c);
        }
        
        A.first = 1; A.second = 1;
        B.first = 10; B.second = 10;
        
        aa.clear(); bb.clear();
        achk = 0; bchk = 0;
        
        for(int k=0; k<n; k++){
            if(visited[k][A.first][A.second] != 0){
                aa.push_back(k);
                achk = 1;
            }
            if(visited[k][B.first][B.second] != 0){
                bb.push_back(k);
                bchk = 1;
            }
        }
        
        maxVal = 0;
        
        if(achk > 0 && !bchk){
            for(int k=0; k<aa.size(); k++){
                maxVal = max(maxVal, ap[aa[k]].p);
            }
        }
        else if(!achk && bchk > 0){
            for(int k=0; k<bb.size(); k++){
                maxVal = max(maxVal, ap[bb[k]].p);
            }
        }
        else if(achk > 0 && bchk > 0){
            for(int k=0; k<aa.size(); k++){
                for(int h=0; h<bb.size(); h++){
                    if(aa[k] == bb[h]){
                        maxVal = max(maxVal, ap[aa[k]].p);
                    }
                    else{
                        maxVal = max(maxVal, ap[aa[k]].p + ap[bb[h]].p);
                    }
                }
            }
        }
        
        sum += maxVal;
        cout << "처음 : " << maxVal << endl;
        
        for(int i=0; i<m; i++){
            if(a[i] == 0 && b[i] != 0){
                A.first += dx[a[i]-1];
                A.second += dy[a[i]-1];
            }
            else if(a[i] != 0 && b[i] == 0){
                B.first += dx[b[i]-1];
                B.second += dy[b[i]-1];
            }
            else if(a[i] != 0 && b[i] != 0){
                A.first += dx[a[i]-1];
                A.second += dy[a[i]-1];
                
                B.first += dx[b[i]-1];
                B.second += dy[b[i]-1];
            }
            
            aa.clear(); bb.clear();
            achk = 0; bchk = 0;
            
            for(int k=0; k<n; k++){
                if(visited[k][A.first][A.second] != 0){
                    aa.push_back(k);
                    achk = 1;
                }
                if(visited[k][B.first][B.second] != 0){
                    bb.push_back(k);
                    bchk = 1;
                }
            }
            
            maxVal = 0;
            
            if(achk > 0 && !bchk){
                for(int k=0; k<aa.size(); k++){
                    maxVal = max(maxVal, ap[aa[k]].p);
                }
            }
            else if(!achk && bchk > 0){
                for(int k=0; k<bb.size(); k++){
                    maxVal = max(maxVal, ap[bb[k]].p);
                }
            }
            else if(!achk && !bchk)
                continue;
            else if(achk > 0 && bchk > 0){
                for(int k=0; k<aa.size(); k++){
                    for(int h=0; h<bb.size(); h++){
                        if(aa[k] == bb[h]){
                            maxVal = max(maxVal, ap[aa[k]].p);
                        }
                        else{
                            maxVal = max(maxVal, ap[aa[k]].p + ap[bb[h]].p);
                        }
                    }
                }
            }
        
            cout << maxVal << endl;
            sum += maxVal;
        }
        
        cout << "#" << t << " " << sum << "\n";
        
        memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
        memset(visited, 0, sizeof(visited)); ap.clear(); sum = 0;
    }
    
    return 0;
}
