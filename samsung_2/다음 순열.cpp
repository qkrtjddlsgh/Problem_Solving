// 다음 순열
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

vector <int> v;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> m;
        v.push_back(m);
    }
        
    if(next_permutation(v.begin(), v.end())){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else
        cout << "-1\n";
    
    return 0;
}
