// 연구소
#include <bits/stdc++.h>
using namespace std;

int n, m, arr[9][9], visit[9][9];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y){
    
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &arr[i][j]);
    
    // 0 : 빈칸, 1 : 벽, 2 : 바이러스
    
    return 0;
}
