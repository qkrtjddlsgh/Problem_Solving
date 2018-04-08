// 스타트와 링크
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum1, sum2, minval, ans = 987654321, arr[21][21], visited[21];

vector <int> a;
vector <int> b;

void func(int index, int cnt){
    visited[index] = 1;
    
    if(cnt == n/2){
        for(int i=0; i<n; i++){
            if(visited[i])
                a.push_back(i);
            else
                b.push_back(i);
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if(i == j)
                    continue;
                else{
                    sum1 += arr[a[i]][a[j]];
                    sum2 += arr[b[i]][b[j]];
                }
            }
        }
        
        minval = abs(sum1 - sum2);
        ans = min(ans, minval);
        
        sum1 = 0; sum2 = 0;
        a.clear(); b.clear();
    }
    else{
        for(int i=index+1; i<n; i++){
            func(i, cnt+1);
        }
    }
    
    visited[index] = 0;
}

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);
    
    func(0, 1);
    
    printf("%d\n", ans);
    return 0;
}

