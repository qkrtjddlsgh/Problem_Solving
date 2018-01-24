// 명령 프롬프트
#include <bits/stdc++.h>
using namespace std;

string s[50];
vector <char> ans;

int chk, cnt;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    for(int i=0; i<s[0].size(); i++){
        char temp = s[0][i];
        
        for(int j=0; j<n; j++){
            if(temp == s[j][i])
                cnt++;
        }
        
        if(cnt == n){
            ans.push_back(temp);
        }
        else
            ans.push_back('?');
        
        cnt = 0;
    }
    
    for(int i=0; i<ans.size(); i++)
        cout << ans[i];
    
    cout << '\n';
    return 0;
}
