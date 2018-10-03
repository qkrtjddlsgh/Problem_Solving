// 퇴사 : 재귀를 이용한 완전탐색 (안고르고 넘어갈수 있음)
#include <iostream>
#include <algorithm>
using namespace std;

int n, maxVal, t[16], p[16];

void func(int index, int sum){
    if(index == n){
        maxVal = max(sum, maxVal);
        return;
    }
    
    if(index + t[index] <= n){
        func(index + t[index], sum + p[index]);
    }
    
    func(index + 1, sum);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }
    
    func(0, 0);
    cout << maxVal << "\n";
    
    return 0;
}
