// 베르트랑 공준
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int arr[246913];

void func(){
    for(int i=0; i<=246912; i++)
        arr[i] = i;
    
    for(int i=2; i<=246912; i++){
        if(!arr[i])
            continue;
        for(int j=i*2; j<=246912; j+=i){
            arr[j] = 0;
        }
    }
}

int main(int argc, char *argv[]){
    
    func();
    
    while(1){
        scanf("%d", &n);
        
        if(n==0)
            return 0;
        
        for(int i=n+1; i<=2*n; i++){
            if(arr[i] != 0)
                cnt++;
        }
        
        cout << cnt << "\n";
        cnt = 0;
    }
    
    return 0;
}
