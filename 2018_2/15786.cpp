#include <iostream>
#include <string>
using namespace std;

int n, m;

string pwd, arr[1001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    cin >> pwd;
    
    for(int i=0; i<m; i++){
        cin >> arr[i];
        int start = 0;
        
        for(int j=0; j<arr[i].size(); j++){
            if(pwd[start] == arr[i][j]){
                start++;
            }
        }
        
        if(start == pwd.size()){
            cout << "true\n";
        }
        else{
            cout << "false\n";
        }
    }
    
    return 0;
}
