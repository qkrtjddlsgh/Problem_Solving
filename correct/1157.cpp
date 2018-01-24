// 단어 공부
#include <bits/stdc++.h>
using namespace std;

string s;
int ans, maxval;
int cnt[150];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    
    for(int i=0; i<s.size(); i++){
        s[i] = toupper(s[i]);
        cnt[(int)s[i]]++;
    }
    
    for(int i=65; i<91; i++){
        if(cnt[i] > maxval){
            maxval = cnt[i];
            ans = i;
        }
    }
    
    for(int i=65; i<91; i++){
        if(i == ans)
            continue;
        else if(maxval == cnt[i]){
            cout << "?\n";
            return 0;
        }
    }
    
    char c = ans;
    cout << c << "\n";
    
    return 0;
}
