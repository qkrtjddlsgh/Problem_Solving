// 수 정렬하기
#include <bits/stdc++.h>
using namespace std;

vector <int> v;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        int idx;
        scanf("%d", &idx);
        v.push_back(idx);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<n; i++)
        printf("%d\n", v[i]);
    
    return 0;
}
