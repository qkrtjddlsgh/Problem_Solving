// 생일
#include <bits/stdc++.h>
using namespace std;

int n;

struct person{
    char name[20];
    int dd;
    int mm;
    int yyyy;
};

struct person p[101];

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%s %d %d %d", p[i].name, &p[i].dd, &p[i].mm, &p[i].yyyy);
    
    sort(p, p+n+1, [](struct person &a, struct person &b){
        if(a.yyyy != b.yyyy)
            return a.yyyy > b.yyyy;
        else if(a.mm != b.mm)
            return a.mm > b.mm;
        else
            return a.dd > b.dd;
    });
    
    printf("%s\n%s\n", p[0].name, p[n-1].name);
    return 0;
}
