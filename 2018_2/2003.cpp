#include <iostream>
using namespace std;

int n, m, ans, sum, arr[10001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            sum += arr[j];
        
            if(sum == m){
                ans++;
                sum = 0;
                break;
            }
            else if(sum > m){
                sum = 0;
                break;
            }
            else if(j == n-1 && sum != m){
                sum = 0;
            }
            else
                continue;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
