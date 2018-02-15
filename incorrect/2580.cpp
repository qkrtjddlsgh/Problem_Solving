// 스도쿠
#include <bits/stdc++.h>
using namespace std;

int sudoku[9][9], chk[9][9];
vector <pair<int,int>> coordi;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> sudoku[i][j];
            
            if(sudoku[i][j] == 0)
                coordi.push_back({i, j});
        }
    }
    
    
    
    return 0;
}
