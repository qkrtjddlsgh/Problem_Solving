// 폰 노이만과 파리
#include <bits/stdc++.h>
using namespace std;

int S, T, D;

int main(int argc, char *argv[]){
    scanf("%d %d %d", &S, &T, &D);
    printf("%d\n", (D/(S*2))*T);
    return 0;
}
