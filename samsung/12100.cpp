// 2048 (Easy)
#include <bits/stdc++.h>
using namespace std;

int n, arr[21][21];

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &arr[i][j]);
    
    return 0;
}
