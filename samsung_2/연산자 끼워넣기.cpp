// 연산자 끼워넣기 : 재귀를 이용한 완전탐색 (무조건 골라야함)
#include <iostream>
#include <algorithm>
using namespace std;

int n, num[11], arr[4], maxVal = -987654321, minVal = 987654321; // maxVal이 -1보다 작을수도 있음 (초기화 조심)

void func(int index, int total, int plus, int minus, int mul, int div){
    if(index == n){
        maxVal = max(maxVal, total);
        minVal = min(minVal, total);
        return;
    }
    
    if(plus > 0){
        func(index + 1, total + num[index], plus - 1, minus, mul, div);
    }
    if(minus > 0){
        func(index + 1, total - num[index], plus, minus - 1, mul, div);
    }
    if(mul > 0){
        func(index + 1, total * num[index], plus, minus, mul - 1, div);
    }
    if(div > 0){
        func(index + 1, total / num[index], plus, minus, mul, div - 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    
    for(int i=0; i<4; i++){
        cin >> arr[i];
    }
    
    func(1, num[0], arr[0], arr[1], arr[2], arr[3]);
    
    cout << maxVal << "\n" << minVal << "\n";
    return 0;
}
