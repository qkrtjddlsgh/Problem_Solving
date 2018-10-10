// 치킨배달 : 중복 불가능한 M개 이하의 순서쌍
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;

int n, m, ans, ans2 = 987654321, minVal, visited[14], arr[51][51];

vector <pair<pii,int>> home;
vector <pii> chicken;

void func(int cur, int cnt){
    if(cur > chicken.size())
        return;
    if(cnt == m){
        for(int i=0; i<home.size(); i++){
            for(int j=0; j<chicken.size(); j++){
                if(visited[j]){
                    home[i].second = min(home[i].second, abs(home[i].first.first - chicken[j].first) + abs(home[i].first.second - chicken[j].second));
                }
            }
        }
        
        for(int i=0; i<home.size(); i++){
            minVal += home[i].second;
            home[i].second = 987654321;
        }
        
        ans2 = min(ans2, minVal);
        minVal = 0;
        
        return;
    }
    
    visited[cur] = 1;
    func(cur + 1, cnt + 1);
    
    visited[cur] = 0;
    func(cur + 1, cnt);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 1){
                home.push_back({{i, j}, 987654321});
            }
            if(arr[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }
    
    if(m == chicken.size()){
        for(int i=0; i<home.size(); i++){
            for(int j=0; j<chicken.size(); j++){
                home[i].second = min(home[i].second, abs(home[i].first.first - chicken[j].first) + abs(home[i].first.second - chicken[j].second));
            }
        }
        
        for(int i=0; i<home.size(); i++){
            ans += home[i].second;
        }
    }
    else{
        func(0, 0);
    }
   
    if(!ans){
        cout << ans2 << "\n";
    }
    else
        cout << ans << "\n";
    
    return 0;
}
