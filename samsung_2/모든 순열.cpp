// 모든 순열
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

vector <int> v;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=1; i<=n; i++)
        v.push_back(i);
    
    do{
        for(int i=0; i<v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
