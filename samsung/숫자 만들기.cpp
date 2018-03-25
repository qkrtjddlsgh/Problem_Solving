// 숫자 만들기
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int tc, n, ans, arr[4], input[13];
int maxval = -987654321, minval = 987654321;

void func(int index, int plus, int minus, int multiple, int divide, int sum){
    if(index == n){
        maxval = max(maxval, sum);
        minval = min(minval, sum);
        return;
    }
    
    if(plus > 0)
        func(index+1, plus-1, minus, multiple, divide, sum + input[index]);
    if(minus > 0)
        func(index+1, plus, minus-1, multiple, divide, sum - input[index]);
    if(multiple > 0)
        func(index+1, plus, minus, multiple-1, divide, sum * input[index]);
    if(divide > 0)
        func(index+1, plus, minus, multiple, divide-1, sum / input[index]);
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int c=0; c<tc; c++){
        scanf("%d", &n);
        
        for(int i=0; i<4; i++)
            scanf("%d", &arr[i]);
        
        for(int i=0; i<n; i++)
            scanf("%d", &input[i]);
        
        func(1, arr[0], arr[1], arr[2], arr[3], input[0]);
        
        ans = maxval - minval;
        
        printf("#%d %d\n", c+1, ans);
        
        ans = 0; maxval = -987654321; minval = 987654321;
    }
    
    return 0;
}
