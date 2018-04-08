// 요리사
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int tc, n, ans1, ans2, minval, realans = 987654321, arr[17][17], visited[17];

vector <int> a;
vector <int> b;

void func(int index, int cnt){
    visited[index] = 1; // 선택
    
    if(cnt == n/2){ // 팀 구성 완료
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
                
                ans1 += arr[a[i]][a[j]];
                ans2 += arr[b[i]][b[j]];
            }
        }
        
        minval = abs(ans1 - ans2);
        realans = min(minval, realans);
        
        ans1 = 0;
        ans2 = 0;
        
        a.clear();
        b.clear();
    }
    else{
        for(int i=index+1; i<n; i++)
            func(i, cnt+1);
    }
    
    visited[index] = 0; // 취소
}

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        scanf("%d", &n);
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &arr[i][j]);
        
        func(0, 1);
        
        printf("#%d %d\n", h+1, realans);
        
        realans = 987654321;
    }
    
    return 0;
}
