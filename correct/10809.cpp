// 알파벳 찾기
#include <bits/stdc++.h>
using namespace std;

string s;
int chk[125];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    
    memset(chk, -1, sizeof(chk));
    
    for(int i=0; i<s.size(); i++){
        if(chk[int(s[i])] == -1)
            chk[int(s[i])] = i;
        else
            continue;
    }
    
    for(int i=97; i<122; i++)
        cout << chk[i] << " ";
    
    cout << chk[122] << "\n";
    return 0;
}
