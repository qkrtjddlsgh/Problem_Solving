// N-Queen
#include <bits/stdc++.h>
using namespace std;

int n, cnt, arr[15];

bool promising(int row){
    if(row < 1)
        return true;
    
    for(int i=0; i<row; i++) // pruning 조건
        if(arr[i] == arr[row] || abs(i-row) == abs(arr[i]-arr[row]))
            return false;
    
    return true;
}

void func(int row, int destRow){
    if(promising(row)){
        if(row == destRow)
            cnt++;
        else{
            for(int j=1; j<=destRow+1; j++){
                arr[row+1] = j;
                func(row+1, destRow);
            }
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    func(-1, n-1);
    cout << cnt << "\n";
    
    return 0;
}
