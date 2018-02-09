// 숨바꼭질
#include <bits/stdc++.h>
using namespace std;

int n, k, visited[100001];

int bfs(int start, int desti){
    visited[start] = 1;
    
    queue <pair<int,int>> q;
    q.push({start, 0});
    
    int cur = 0;
    int time = 0;
    
    while(!q.empty()){
        cur = q.front().first;
        time = q.front().second;
        q.pop();
        
        if(cur == desti) // 동생을 찾았을때
            break;
        
        if(visited[cur+1] == 0 && cur+1 <= 100000 && cur+1 >= 0){
            visited[cur+1] = 1;
            q.push({cur+1, time+1});
        }
        if(visited[cur-1] == 0 && cur-1 <= 100000 && cur-1 >= 0){
            visited[cur-1] = 1;
            q.push({cur-1, time+1});
        }
        if(visited[2*cur] == 0 && 2*cur <= 100000 && 2*cur >= 0){
            visited[2*cur] = 1;
            q.push({2*cur, time+1});
        }
        
    }
    
    return time;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    
    cout << bfs(n, k) << "\n";
    return 0;
}
