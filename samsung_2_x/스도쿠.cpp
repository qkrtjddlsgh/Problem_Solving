// 스도쿠
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ans, cnt, row_cnt, col_cnt, arr[10][10], chk[10], visited[10];

vector <pair<int,int>> pos;

void row_chk(int row){
    memset(chk, 0, sizeof(chk));
    cnt = 0;
    
    for(int i=0; i<9; i++){
        if(!arr[row][i])
            cnt++;
        
        chk[arr[row][i]] += 1;
    }
    
    if(cnt == 1){
        int num = 0;
        
        for(int i=1; i<=9; i++)
            if(!chk[i])
                num = i;
        
        for(int i=0; i<9; i++){
            if(!arr[row][i]){
                arr[row][i] = num;
                break;
            }
        }
    }
    else if(cnt == 0){
        for(int i=1; i<=9; i++){
            if(chk[i] == 1)
                cnt++;
        }
        
        if(cnt == 9)
            row_cnt++;
    }
}

void col_chk(int col){
    memset(chk, 0, sizeof(chk));
    cnt = 0;
    
    for(int i=0; i<9; i++){
        if(!arr[i][col])
            cnt++;
        
        chk[arr[i][col]] = 1;
    }
    
    if(cnt == 1){
        int num = 0;
        
        for(int i=1; i<=9; i++)
            if(!chk[i])
                num = i;
        
        for(int i=0; i<9; i++){
            if(!arr[i][col]){
                arr[i][col] = num;
                break;
            }
        }
    }
    else if(cnt == 0){
        for(int i=1; i<=9; i++){
            if(chk[i] == 1)
                cnt++;
        }
        
        if(cnt == 9)
            col_cnt++;
    }
}

void func(int cur){
    if(ans)
        return;
    if(cur > pos.size())
        return;
    if(cur == pos.size()){
        for(int i=0; i<pos.size(); i++){
            arr[pos[i].first][pos[i].second] = visited[i];
        }
        
        row_cnt = 0;
        col_cnt = 0;
        
        for(int i=0; i<9; i++){
            row_chk(i);
            col_chk(i);
        }
        
        if(row_cnt == 9 && col_cnt == 9){
            ans = 1;
            
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        return;
    }
    
    for(int i=1; i<=9; i++){
        visited[cur] = i;
        func(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<9; i++)
        row_chk(i);
    
    for(int i=0; i<9; i++)
        col_chk(i);
    
    for(int i=0; i<9; i++)
        row_chk(i);
    
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(!arr[i][j])
                pos.push_back({i, j});
    
    func(0);
    
    return 0;
}
