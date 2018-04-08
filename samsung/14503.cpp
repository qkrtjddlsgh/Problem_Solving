// 로봇 청소기
#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c, d, arr[51][51], visited[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y, int direct){
    queue <pair<int,int>, int> q;
    q.push({{x, y}, direct});
    
    while(!q.empty()){
        //int nx = q.front().first.first;
        //int ny = q.front().first.second;
        //int ndirect = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // 0 : 빈칸, 1 : 벽
            scanf("%d", &arr[i][j]);
        }
    }
    
    visited[r][c] = 1;
    bfs(r, c, d);
    
    cout << "hi\n";
    return 0;
}

// r,c : 초기 위치
// d : 0-북, 1-동, 2-남, 3-서

// 1. 현재 위치를 청소한다
// 2. 왼쪽 방향을 아직 청소하지 않았다면 왼쪽으로 한칸 전진후 1번으로 돌아감
// 3. 왼쪽 방향에 청소할 공간이 없다면 그 방향으로 회전하고 2번으로 돌아감
// 4. 네 방향 모두가 청소가 되있거나 벽이라면 바라보는 방향을 유지한 채로 한 칸을 후진하고 2번으로 돌아감
// 5. 네 방향 모두가 청소가 되있거나 벽이면서 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다
