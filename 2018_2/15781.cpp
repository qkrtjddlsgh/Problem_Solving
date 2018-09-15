#include <iostream>
#include <algorithm>
using namespace std;

int N, M, n[1001], m[1001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    
    for(int i=0; i<N; i++)
        cin >> n[i];
    
    for(int j=0; j<M; j++)
        cin >> m[j];
    
    sort(n, n+N);
    sort(m, m+M);
        
    cout << n[N-1] + m[M-1] << "\n";
    return 0;
}
