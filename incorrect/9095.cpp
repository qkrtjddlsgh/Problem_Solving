// 1,2,3 더하기
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[11] = {0, 1, 2, 4};

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=4; i<=10; i++)
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        
        cout << arr[temp] << "\n";
    }
    
    return 0;
}
