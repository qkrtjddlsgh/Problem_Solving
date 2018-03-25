// 연산자 끼워넣기
#include <iostream>
#include <algorithm>
using namespace std;

int n, input[101], arr[4];
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
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d", &input[i]);
    
    // + - * /
    for(int i=0; i<4; i++)
        scanf("%d", &arr[i]);
    
    func(1, arr[0], arr[1], arr[2], arr[3], input[0]);
    
    printf("%d\n%d\n", maxval, minval);
    return 0;
}
