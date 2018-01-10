// 콘테스트
#include <bits/stdc++.h>
using namespace std;

int w[10], k[10];

int main(int argc, char *argv[]){
    
    for(int i=0; i<10; i++)
        scanf("%d", &w[i]);
    
    for(int i=0; i<10; i++)
        scanf("%d", &k[i]);
    
    sort(w, w+10);
    sort(k, k+10);
    
    cout << w[7] + w[8] + w[9] << "\n" << k[7] + k[8] + k[9] << "\n";
    return 0;
}
