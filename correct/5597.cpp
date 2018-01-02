// 과제 안 내신 분..?
#include <bits/stdc++.h>
using namespace std;

int chk[31];

int main(int argc, char *argv[]){
    
    for(int i=0; i<28; i++){
        int temp;
        scanf("%d", &temp);
        chk[temp] = 1;
    }
    
    for(int i=1; i<=30; i++){
        if(!chk[i])
            cout << i << "\n";
    }
    
    return 0;
}
