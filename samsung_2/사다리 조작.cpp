// 사다리 조작 : 중복 없는 완전탐색
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, h, x, y, cnt, ans = -1, sero[15], visited[305], arr[35][15];

vector <pair<int,int>> garo;
vector <pair<int,int>> poss;
vector <pair<int,int>> temp;

void swap(int a, int b){
    int temp = sero[a];
    sero[a] = sero[b];
    sero[b] = temp;
}

void func(int cur, int cnt, int add){
    visited[cur] = 1;
    
    if(cur >= poss.size())
        return;
    if(cnt == add){
        temp.clear();
        
        // copy vector
        for(int i=0; i<garo.size(); i++){
            temp.push_back({garo[i].first, garo[i].second});
        }
        // add element
        for(int i=0; i<poss.size(); i++){
            if(visited[i]){
                if(!arr[poss[i].first][poss[i].second] && !arr[poss[i].first][poss[i].second + 1]){
                    arr[poss[i].first][poss[i].second] = 1;
                    arr[poss[i].first][poss[i].second + 1] = 1;
                    
                    temp.push_back({poss[i].first, poss[i].second});
                }
            }
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i=1; i<=n; i++)
            sero[i] = i;
        
        for(int i=0; i<temp.size(); i++)
            swap(temp[i].second, temp[i].second + 1);
        
        cnt = 0;
        
        for(int i=1; i<=n; i++){
            if(sero[i] == i)
                cnt++;
            else
                break;
        }
        
        for(int i=0; i<temp.size(); i++){
            arr[temp[i].first][temp[i].second] = 0;
            arr[temp[i].first][temp[i].second + 1] = 0;
        }
        
        if(cnt == n){
            ans = add;
            return;
        }
    }
    else{
        for(int i=cur+1; i<poss.size(); i++){
            func(i, cnt + 1, add);
        }
    }
    
    visited[cur] = 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m >> h;
    
    for(int i=1; i<=n; i++)
        sero[i] = i;
    
    for(int i=0; i<m; i++){
        cin >> x >> y;
        garo.push_back({x, y});
        
        arr[x][y] = 1;
        arr[x][y+1] = 1;
    }
    
    sort(garo.begin(), garo.end());
    
    for(int i=0; i<m; i++){
        swap(garo[i].second, garo[i].second + 1);
    }
    
    for(int i=1; i<=n; i++){
        if(sero[i] == i)
            cnt++;
        else
            break;
    }
    
    if(cnt == n){
        cout << "0\n";
        return 0;
    }
    else{
        for(int i=1; i<=h; i++){
            for(int j=1; j<n; j++){
                if(!arr[i][j] && !arr[i][j+1]){
                    poss.push_back({i, j});
                }
            }
        }
        
        for(int i=1; i<4; i++){
            for(int j=0; j<poss.size(); j++){
                func(j, 1, i);
                
                if(ans != -1){
                    cout << ans << "\n";
                    return 0;
                }
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}
