// 시험 감독
#include <iostream>
using namespace std;

long long arr[1000001], b, c, ans;

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    
    scanf("%lld %lld", &b, &c);
    
    for(int i=0; i<n; i++){
        arr[i] -= b;
        
        if(arr[i] > 0){
            if(arr[i] % c == 0)
                ans += arr[i] / c;
            else
                ans += arr[i] / c + 1;
        }
    }
    
    printf("%lld\n", ans + n);
    return 0;
}

