#include <bits/stdc++.h>
using namespace std;

int g, p, t1, t2, cnt;
int pp[100001];

int find(int x){
    if(pp[x] == x) return x;
    return pp[x] = find(pp[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    pp[a] = b;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &g);
    scanf("%d", &p);
    
    bool chk = true;
    
    for(int i=0; i<=g; i++)
        pp[i] = i;
    
    for(int i=0; i<p; i++){
        scanf("%d", &t1);
        t2 = find(t1);
        
        if(t2 == 0)
            chk = false;
        
        if(chk){
            merge(t2, t2-1);
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
