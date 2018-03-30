// 로봇 청소기
#include <iostream>
using namespace std;

int n, m, r, c, d, arr[51][51];

// r,c : 초기 위치
// d : 0-북, 1-동, 2-남, 3-서

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    cout << "hi\n";
    return 0;
}
