// 암호 만들기
#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[16];

// 한 개의 모음, 두 개의 자음
void chk(int index, int count, int mo, int ja, string ans){
    if(count == l && mo >= 1 && ja >= 2){ // 정답일경우 출력
        cout << ans << "\n";
        return;
    }
    if(index == c)
        return;
    
    // 모음을 선택할경우
    if(arr[index] == 'a' || arr[index] == 'e' || arr[index] == 'i' || arr[index] == 'o' || arr[index] == 'u')
        chk(index+1, count+1, mo+1, ja, ans + arr[index]);
    else // 자음을 선택할경우
        chk(index+1, count+1, mo, ja+1, ans + arr[index]);
    
    // 선택하지않고 넘어갈 경우
    chk(index+1, count, mo, ja, ans);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> l >> c;
    
    for(int i=0; i<c; i++)
        cin >> arr[i];
    
    // a c i s t w
    sort(arr, arr+c);
    chk(0, 0, 0, 0, "");
    
    return 0;
}
