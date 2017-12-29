// 간지
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    printf("%c%d\n", (n+8) % 12 + 'A', (n+6) % 10);
    return 0;
}
