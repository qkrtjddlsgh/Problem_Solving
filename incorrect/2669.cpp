// 직사각형 네개의 합집합의 면적 구하기
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct point p[4];

int main(int argc, char *argv[]){
    for(int i=0; i<4; i++)
        scanf("%d %d %d %d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
    
    return 0;
}
