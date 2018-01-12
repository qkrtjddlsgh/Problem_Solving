// 에라토스테네스의 체
#include <bits/stdc++.h>
using namespace std;

int n, k, cnt, chk;
int arr[1001];

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &k);
    
    for(int i=0; i<=n; i++)
        arr[i] = i;
    
    for(int i=2; i<=n; i++){
        if(!arr[i])
            continue;
        for(int j=i; j<=n; j+=i){
            if(!arr[j])
                continue;
            
            arr[j] = 0;
            cnt++;
            
            if(cnt == k){
                chk = j;
            }
        }
    }
    
    cout << chk << "\n";
    return 0;
}
