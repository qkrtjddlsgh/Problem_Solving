// 째로탈출 2
#include <bits/stdc++.h>
using namespace std;

int n, m, visited[11][11];
char input[11][11];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &input[i][j]);

    return 0;
}
