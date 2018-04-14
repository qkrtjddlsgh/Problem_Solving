// N과 M (2) : 중복 순열
#include <iostream>
using namespace std;

int n, m, arr[9];

void func(int cur){
    if(cur == m){
        for(int i=0; i<m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    
    for(int i=1; i<=n; i++){
        arr[cur] = i;
        func(cur+1);
    }
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    func(0);
    
    return 0;
}
