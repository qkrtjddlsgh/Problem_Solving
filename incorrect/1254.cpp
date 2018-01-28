// 팰린드롬 만들기
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    
    if(s.size()%2 == 0){ // 짝수개일때
        
    }
    else{ // 홀수개일때
        for(int i=0; i<s.size()/2; i++){
            if(s[i] == s[s.size()-i-1])
                cnt++;
            
            // 0 1 2 3 4
            // a b b b a
        }
        
        if(cnt == s.size()/2)
            cout << s.size() << "\n";
        
        else if(cnt < s.size()/2){
            
        }
        else if(cnt > s.size()/2){
            
        }
    }
    
    return 0;
}
