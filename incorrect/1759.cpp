// 암호 만들기
#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[16];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> l >> c;
    
    for(int i=0; i<c; i++)
        cin >> arr[i];
    
    sort(arr, arr+c);
    
    
    
    return 0;
}
