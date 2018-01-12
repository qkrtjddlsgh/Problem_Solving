// 점수 계산
#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v;
vector <int> q;
int temp, sum;

int main(int argc, char *argv[]){
    
    for(int i=0; i<8; i++){
        scanf("%d", &temp);
        v.push_back({temp, i});
    }
    
    sort(v.begin(), v.end());
    
    for(int i=3; i<8; i++){
        sum += v[i].first;
        q.push_back(v[i].second + 1);
    }
    
    cout << sum << "\n";
    
    sort(q.begin(), q.end());
    
    for(int i=0; i<4; i++){
        cout << q[i] << " ";
    }
    
    cout << q[4] << "\n";
    return 0;
}
