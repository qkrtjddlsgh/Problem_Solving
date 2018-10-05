// 스타트와 링크 : 재귀를 이용한 완전탐색 (모든 순서쌍 구하기)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, minVal = 987654321, sumA, sumB, arr[21][21], visited[21];

vector <int> a;
vector <int> b;

void func(int index, int cnt){
    visited[index] = 1;
    
    if(cnt == n/2){
        for(int i=0; i<n; i++){
            if(visited[i]){
                a.push_back(i);
            }
            else{
                b.push_back(i);
            }
        }
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if(i == j)
                    continue;

                sumA += arr[a[i]][a[j]];
                sumB += arr[b[i]][b[j]];
            }
        }

        minVal = min(minVal, abs(sumA - sumB));
        
        a.clear(); sumA = 0;
        b.clear(); sumB = 0;
    }
    else{
        for(int i=index+1; i<n; i++){
            func(i, cnt+1);
        }
    }
    
    visited[index] = 0;
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    func(0, 1);
    
    cout << minVal << "\n";
    return 0;
}
