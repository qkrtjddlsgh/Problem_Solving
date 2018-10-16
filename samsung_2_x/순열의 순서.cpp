// 순열의 순서
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, num, cnt = 1, k;

vector <int> v;
vector <int> w;

int comp(){
    int same = 0;
    
    for(int i=0; i<v.size(); i++)
        if(v[i] == w[i])
            same++;
    
    if(same == v.size())
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> num;
    
    if(num == 1){
        cin >> k;
        
        for(int i=1; i<=n; i++)
            v.push_back(i);
        
        for(int i=1; i<k; i++)
            next_permutation(v.begin(), v.end());
        
        for(int i=0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
    }
    else if(num == 2){
        for(int i=1; i<=n; i++)
            v.push_back(i);
        
        for(int i=0; i<n; i++){
            cin >> m;
            w.push_back(m);
        }
        
        if(comp()){
            cout << "1\n";
            return 0;
        }
            
        while(1){
            next_permutation(v.begin(), v.end());
            cnt++;
            
            if(comp()){
                cout << cnt << "\n";
                return 0;
            }
        }
    }
    
    return 0;
}
