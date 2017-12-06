// 홀수일까 짝수일까
#include <bits/stdc++.h>
using namespace std;

int n; char num[61];

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%s", num);
        
        if(num[strlen(num)-1] % 2 == 0)
            printf("even\n");
        else
            printf("odd\n");
    }
    
    return 0;
}
