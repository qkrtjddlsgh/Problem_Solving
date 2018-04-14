// 부분집합의 합
#include <bits/stdc++.h>
using namespace std;

int n, s, ans, arr[21];

void func(int index, int sum){
    sum += arr[index];
    
    if(index >= n)
        return;
    if(sum == s)
        ans++;
    
    func(index+1, sum-arr[index]);
    func(index+1, sum);
}

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    func(0, 0);
    
    printf("%d\n", ans);
    return 0;
}
