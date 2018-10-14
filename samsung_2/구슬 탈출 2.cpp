// 구슬 탈출 2 : 문제를 꼼꼼히 읽고 예외 처리를 잘하자!!
#include <iostream>
using namespace std;

int n, m, order, ans = -1, rans = -1, bans = -1, visited[12]; char arr[12][12], map[12][12];

pair<int,int> red[2];
pair<int,int> blue[2];

void checkPosition(int dir){
    if(dir == 1){ // 동
        if(red[1].first == blue[1].first){
            if(red[1].second > blue[1].second)
                order = 1; // red first
            else
                order = 0; // blue first
        }
    }
    if(dir == 2){ // 서
        if(red[1].first == blue[1].first){
            if(red[1].second < blue[1].second)
                order = 1; // red first
            else
                order = 0; // blue first
        }
    }
    if(dir == 3){ // 남
        if(red[1].second == blue[1].second){
            if(red[1].first > blue[1].first)
                order = 1;
            else
                order = 0;
        }
    }
    if(dir == 4){ // 북
        if(red[1].second == blue[1].second){
            if(red[1].first < blue[1].first)
                order = 1;
            else
                order = 0;
        }
    }
}

void red_sol(int dir){
    if(dir == 1){
        for(int i=red[1].second+1; i<m-1; i++){
            if(arr[red[1].first][i] == 'O'){ // 탈출
                rans = 1;
                
                arr[red[1].first][i-1] = '.';
                return;
            }
            if(arr[red[1].first][i] == '.'){ // 이동
                red[1].second = i;
                
                arr[red[1].first][i-1] = '.';
                arr[red[1].first][i] = 'R';
            }
            if(arr[red[1].first][i] == 'B') // 정지
                break;
            if(arr[red[1].first][i] == '#') // 정지
                break;
        }
    }
    else if(dir == 2){
        for(int i=red[1].second-1; i>0; i--){
            if(arr[red[1].first][i] == 'O'){ // 탈출
                rans = 1;
                
                arr[red[1].first][i+1] = '.';
                return;
            }
            if(arr[red[1].first][i] == '.'){ // 이동
                red[1].second = i;
                
                arr[red[1].first][i+1] = '.';
                arr[red[1].first][i] = 'R';
            }
            if(arr[red[1].first][i] == 'B') // 정지
                break;
            if(arr[red[1].first][i] == '#') // 정지
                break;
        }
    }
    else if(dir == 3){
        for(int i=red[1].first+1; i<n-1; i++){
            if(arr[i][red[1].second] == 'O'){ // 탈출
                rans = 1;
                
                arr[i-1][red[1].second] = '.';
                return;
            }
            if(arr[i][red[1].second] == '.'){ // 이동
                red[1].first = i;
                
                arr[i-1][red[1].second] = '.';
                arr[i][red[1].second] = 'R';
            }
            if(arr[i][red[1].second] == 'B') // 정지
                break;
            if(arr[i][red[1].second] == '#') // 정지
                break;
        }
    }
    else if(dir == 4){
        for(int i=red[1].first-1; i>0; i--){
            if(arr[i][red[1].second] == 'O'){ // 탈출
                rans = 1;
                
                arr[i+1][red[1].second] = '.';
                return;
            }
            if(arr[i][red[1].second] == '.'){ // 이동
                red[1].first = i;
                
                arr[i+1][red[1].second] = '.';
                arr[i][red[1].second] = 'R';
            }
            if(arr[i][red[1].second] == 'B') // 정지
                break;
            if(arr[i][red[1].second] == '#') // 정지
                break;
        }
    }
}

void blue_sol(int dir){
    if(dir == 1){
        for(int i=blue[1].second+1; i<m-1; i++){
            if(arr[blue[1].first][i] == 'O'){ // 탈출
                bans = 2;
                
                arr[blue[1].first][i-1] = '.';
                return;
            }
            if(arr[blue[1].first][i] == '.'){ // 이동
                blue[1].second = i;
                
                arr[blue[1].first][i-1] = '.';
                arr[blue[1].first][i] = 'B';
            }
            if(arr[blue[1].first][i] == 'R') // 정지
                break;
            if(arr[blue[1].first][i] == '#') // 정지
                break;
        }
    }
    else if(dir == 2){
        for(int i=blue[1].second-1; i>0; i--){
            if(arr[blue[1].first][i] == 'O'){ // 탈출
                bans = 2;
                
                arr[blue[1].first][i+1] = '.';
                return;
            }
            if(arr[blue[1].first][i] == '.'){ // 이동
                blue[1].second = i;
                
                arr[blue[1].first][i+1] = '.';
                arr[blue[1].first][i] = 'B';
            }
            if(arr[blue[1].first][i] == 'R') // 정지
                break;
            if(arr[blue[1].first][i] == '#') // 정지
                break;
        }
    }
    else if(dir == 3){
        for(int i=blue[1].first+1; i<n-1; i++){
            if(arr[i][blue[1].second] == 'O'){ // 탈출
                bans = 2;
                
                arr[i-1][blue[1].second] = '.';
            }
            if(arr[i][blue[1].second] == '.'){ // 이동
                blue[1].first = i;
                
                arr[i-1][blue[1].second] = '.';
                arr[i][blue[1].second] = 'B';
            }
            if(arr[i][blue[1].second] == 'R') // 정지
                break;
            if(arr[i][blue[1].second] == '#') // 정지
                break;
        }
    }
    else if(dir == 4){
        for(int i=blue[1].first-1; i>0; i--){
            if(arr[i][blue[1].second] == 'O'){ // 탈출
                bans = 2;
                
                arr[i+1][blue[1].second] = '.';
                return;
            }
            if(arr[i][blue[1].second] == '.'){ // 이동
                blue[1].first = i;
                
                arr[i+1][blue[1].second] = '.';
                arr[i][blue[1].second] = 'B';
            }
            if(arr[i][blue[1].second] == 'R') // 정지
                break;
            if(arr[i][blue[1].second] == '#') // 정지
                break;
        }
    }
}

void func(int cur, int num){
    if(cur == num){
        // copy array
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                arr[i][j] = map[i][j];
        
        red[1].first = red[0].first;
        red[1].second = red[0].second;
        
        blue[1].first = blue[0].first;
        blue[1].second = blue[0].second;
        
        for(int i=0; i<num; i++){
            checkPosition(visited[i]);
    
            rans = -1;
            bans = -1;
            
            if(order == 1){
                red_sol(visited[i]);
                blue_sol(visited[i]);
            }
            else if(order == 0){
                blue_sol(visited[i]);
                red_sol(visited[i]);
            }
            
            if(bans == 2 && rans == -1)
                break;
            if(bans == 2 && rans == 1)
                break;
            
            if(bans == -1 && rans == 1){ // 성공
                ans = num;
                return;
            }
        }
        
        return;
    }
    
    for(int i=1; i<=4; i++){
        visited[cur] = i;
        func(cur + 1, num);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 'R'){
                red[0].first = i;
                red[0].second = j;
            }
            if(map[i][j] == 'B'){
                blue[0].first = i;
                blue[0].second = j;
            }
        }
    }
    
    for(int i=1; i<11; i++){
        func(0, i);

        if(ans != -1)
            break;
    }
    
    cout << ans << "\n";
    return 0;
}
