// 알파벳 개수
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[150];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    
    for(int i=0; i<s.size(); i++){
        cnt[(int)s[i]]++;
    }
    
    for(int i=97; i<122; i++)
        cout << cnt[i] << " ";
    
    cout << cnt[122] << "\n";
    return 0;
}
