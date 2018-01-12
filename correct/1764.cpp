// 듣보잡
#include <bits/stdc++.h>
using namespace std;

int n, m;
set <string> s;
string temp;

int main(int argc, char *argv[]){
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        cin >> temp;
        s.insert(temp);
    }
    
    vector <string> res;
    
    for(int i=0; i<m; i++){
        cin >> temp;
        
        if(s.count(temp)) // temp와 일치하는 원소 반환
            res.push_back(temp);
    }
    
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    
    for(int i=0; i<res.size(); i++)
        cout << res[i] << "\n";
    
    return 0;
}
