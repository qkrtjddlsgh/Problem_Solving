// 구슬 탈출 2
#include <iostream>
using namespace std;

int n, m, arr[11][11];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    return 0;
}
