#include <iostream>
using namespace std;

int n, a, b, arr[1001][1001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i == a-1 && arr[i][j] > arr[a-1][b-1]) || (j == b-1 && arr[i][j] > arr[a-1][b-1])){
                cout << "ANGRY\n";
                return 0;
            }
        }
    }
    
    cout << "HAPPY\n";
    return 0;
}
