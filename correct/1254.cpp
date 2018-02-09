// 팰린드롬 만들기
#include <bits/stdc++.h>
using namespace std;

string s, temp;
int minval;

bool isPalin(string a){
    int len = (int)a.size()-1;
    int idx = 0;
    
    while(len > idx){
        if(a[idx++] != a[len--])
            return false;
    }
    
    return true;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    temp = s;
    
    if(isPalin(s)){
        cout << s.size() << "\n";
        return 0;
    }
    
    reverse(s.begin(), s.end());
    temp += s;
    
    for(int i=0; i<s.size(); i++){
        if(isPalin(temp))
            minval = (int)temp.size();
        
        string x;
        
        for(int j=0; j<temp.size(); j++){
            if(j == s.size())
                continue;
            x += temp[j];
        }
        
        temp = x;
    }
    
    cout << minval << "\n";
    return 0;
}
