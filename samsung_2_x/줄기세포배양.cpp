// 줄기세포배양
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tc, n, m, k, nx, ny, virus_size, ans, pos;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct info{
    int x;
    int y;
    int val;
    int time;
    int death;
    int state; // 0 : 비활성, 1 : 활성, 2 : 죽음
};

vector <info> v;
queue <pair<int,pair<int,int>>> q;

int double_check(int nx, int ny, int val){
    for(int i=0; i<v.size(); i++){
        if(v[i].x == nx && v[i].y == ny && v[i].val > val && v[i].state == 0)
            return 0; // 미갱신
        if(v[i].x == nx && v[i].y == ny && v[i].val < val && v[i].state == 0 && v[i].time == v[i].val){
            v[i].val = val; // 갱신
            return 2;
        }
        if(v[i].x == nx && v[i].y == ny && (v[i].state == 0 || v[i].state == 1 || v[i].state == 2)){
            return 2;
        }
    }
    return 1;
}

void spread(){
    while(!q.empty()){
        int val = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            pos = double_check(nx, ny, val);
            
            if(pos == 1)
                v.push_back({nx, ny, val, val, val, 0});
            else
                continue;
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> n >> m >> k;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> pos;
                
                if(pos != 0)
                    v.push_back({i, j, pos, pos, pos, 0}); // val, time, death, state
            }
        }
        
        k += 1;
        
        while(k--){
            virus_size = (int)v.size();
            
            for(int i=0; i<virus_size; i++){
                if(v[i].time > 0 && v[i].state == 0){ // 비활성 상태일 경우
                    v[i].time -= 1;
                }
                else if(v[i].time == 0){ // 활성 상태일 경우 최초 한시간
                    v[i].time -= 1;
                    v[i].death -= 1;
                    v[i].state = 1; // 활성
                    
                    q.push({v[i].val, {v[i].x, v[i].y}});
                }
                else if(v[i].death == 0){
                    v[i].state = 2; // 죽음
                }
                else if(v[i].state == 1 && v[i].death > 0){ // 활성 상태일 경우
                    v[i].death -= 1;
                }
            }
            
            spread(); // 전파
        }
        
        for(int i=0; i<v.size(); i++){
            if(v[i].state <= 1)
                ans++;
        }
        
        cout << "#" << t << " " << ans << "\n";
        
        while(!q.empty())
            q.pop();
        
        v.clear();
        ans = 0;
    }
    
    return 0;
}
