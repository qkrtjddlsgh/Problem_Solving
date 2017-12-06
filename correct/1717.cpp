#include <bits/stdc++.h>
using namespace std;

int n, m;
int x, y, z;
int p[1000001];

int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b)
        return;
    p[b] = a;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    memset(&p, -1, sizeof(p));
    
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &x, &y, &z);
        
        if(x == 0){
            merge(y, z);
        }
        else if(x == 1){
            int res = find(y);
            int res1 = find(z);
            
            if(res == res1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    
    return 0;
}
