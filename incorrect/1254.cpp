// 팰린드롬 만들기
#include <bits/stdc++.h>
using namespace std;

string s;

bool isPalin(string a){
    int cnt = 0;
    
    if(a.size()%2 == 0){ // 짝수
        for(int i=0; i<a.size()/2-1; i++){
            if(a[i] == a[a.size()-i-1])
               cnt++;
        }
               
       if(cnt == a.size()/2)
           return true;
       else
           return false;
    }
    else{ // 홀수
        for(int i=0; i<a.size()/2; i++){
            if(a[i] == a[a.size()-i-1])
                cnt++;
        }
        
        if(cnt == a.size()/2)
            return true;
        else
            return false;
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> s;
    
    cout << isPalin(s) << endl;
    
    return 0;
}
