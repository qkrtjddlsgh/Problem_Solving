// KMP는 왜 KMP일까?
#include <bits/stdc++.h>
using namespace std;

vector <char> v;
string s;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    
    for(int i=0; i<s.size(); i++){
        if(i == 0)
            v.push_back(s[i]);
        if(int(s[i]) == 45)
            v.push_back(s[i+1]);
    }
    
    for(int i=0; i<v.size(); i++)
        cout << v[i];
    
    cout << "\n";
    return 0;
}
