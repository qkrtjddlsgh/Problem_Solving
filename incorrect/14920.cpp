// 3n+1 수열
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int start; int i=2; int cnt=1;
    scanf("%d", &start);
    
    while(start != 4){
        if(i%2 == 0)
            start /= 2;
        else
            start = 3*start + 1;
        i++;
        cnt++;
    }
    
    printf("%d\n", cnt+2);
    return 0;
}
