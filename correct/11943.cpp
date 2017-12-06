// 파일 옮기기
#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;

int main(int argc, char *argv[]){
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", min(a+d, b+c));
    return 0;
}
