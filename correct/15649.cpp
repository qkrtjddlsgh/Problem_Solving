// N과 M (1) : 순열
#include <iostream>
using namespace std;

int n, m, arr[9], visited[9];

void func(int cur){
    if(cur == m){
        for(int i=0; i<m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = 1;
            
            arr[cur] = i;
            func(cur+1);
            
            visited[i] = 0;
        }
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    func(0);
    
    return 0;
}
