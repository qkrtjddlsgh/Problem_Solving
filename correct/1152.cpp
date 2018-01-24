// 단어의 개수
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    getline(cin, s);
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' ')
            continue;
        else if(s[i] != ' '){
            while(1){
                if(s[i] == ' ') // 공백 문자
                    break;
                if(s[i] == '\0') // 마지막 문자
                    break;
                else
                    i++;
            }
            cnt++;
        }
    }
    
    cout << cnt << "\n";
    return 0;
}
