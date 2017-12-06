// 개표
#include <bits/stdc++.h>
using namespace std;

int n, res1, res2;
char s[16];

int main(int argc, char *argv[]){
    scanf("%d", &n);
    scanf("%s", s);
    
    for(int i=0; i<n; i++){
        if(s[i] == 'A') res1++;
        else if(s[i] == 'B') res2++;
    }
    
    if(res1 > res2)
        cout << "A" << "\n";
    else if(res1 < res2)
        cout << "B" << "\n";
    else
        cout << "Tie" << "\n";
    
    return 0;
}
