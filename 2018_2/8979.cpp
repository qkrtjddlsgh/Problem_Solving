#include <iostream>
#include <algorithm>
using namespace std;

int n, k, nation, cnt, arr[1001][4];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        
        if(arr[i][0] == k){
            nation = i;
        }
    }
    
    for(int i=0; i<n; i++){
        if(arr[i][1] > arr[nation][1]){
            cnt++;
        }
        else if(arr[i][1] == arr[nation][1] && arr[i][2] > arr[nation][2]){
            cnt++;
        }
        else if(arr[i][1] == arr[nation][1] && arr[i][2] == arr[nation][2] && arr[i][3] > arr[nation][3]){
            cnt++;
        }
    }
    
    cout << cnt + 1 << "\n";
    return 0;
}
