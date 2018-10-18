// 점심 식사시간
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int tc, n, dist, cnt, timer, ans = 987654321, full[2], visited[11], arr[11][11];

struct info{
    int distance;
    int stair;
    int person;
    int time;
};

bool comp(const info &a, const info &b){
    return a.distance > b.distance;
}

vector <pair<int,int>> person;
vector <pair<int,pair<int,int>>> stair;
vector <info> waitings;

void func(int cur){
    if(cur > person.size())
        return;
    if(cur == person.size()){
        for(int i=0; i<person.size(); i++){
            dist = abs(stair[visited[i]].second.first - person[i].first) + abs(stair[visited[i]].second.second - person[i].second);
            waitings.push_back({dist, visited[i], i, stair[visited[i]].first});
        }
        
        sort(waitings.begin(), waitings.end(), comp);
        
        while(1){
            if(cnt == person.size())
                break;
            
            for(int i=0; i<stair.size(); i++){
                for(int j=0; j<waitings.size(); j++){
                    if(i == waitings[j].stair){
                        if(waitings[j].distance < 0 && waitings[j].time > 0){ // 내려감
                            waitings[j].time -= 1;
                            
                            if(waitings[j].time == 0){ // 다내려감
                                full[waitings[j].stair] -= 1;
                                cnt++;
                            }
                        }
                        if(waitings[j].distance == 0 && waitings[j].time > 0 && full[waitings[j].stair] < 3){ // 처음 내려감
                            full[waitings[j].stair] += 1;
                            waitings[j].distance -= 1;
                            waitings[j].time -= 1;
                            
                            if(waitings[j].time == 0){ // 다내려감
                                full[waitings[j].stair] -= 1;
                                cnt++;
                            }
                        }
                        if(waitings[j].distance > 0){ // 도착전
                            waitings[j].distance -= 1;
                        }
                    }
                }
            }
            
            timer++;
        }
        
        ans = min(ans, timer + 1);
        timer = 0; cnt = 0;
    }
    
    for(int i=0; i<stair.size(); i++){
        visited[cur] = i;
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                
                if(arr[i][j] == 1)
                    person.push_back({i, j});
                else if(arr[i][j] > 1)
                    stair.push_back({arr[i][j], {i, j}});
            }
        }
        
        func(0);
        
        cout << "#" << t << " " << ans << "\n";
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        
        person.clear(); stair.clear(); waitings.clear();
        ans = 987654321; cnt = 0; timer = 0;
    }
    
    return 0;
}
