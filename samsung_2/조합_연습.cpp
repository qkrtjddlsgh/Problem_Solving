// 조합_연습
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, e, arr[9], visited[9];

vector <int> v;

void func6(int cur){
    if(cur == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            visited[i] = 1;
            
            arr[cur] = v[i];
            func6(cur + 1);
            
            visited[i] = 0;
        }
    }
}

void func5(int cur){
    if(cur == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        arr[cur] = v[i];
        func5(cur + 1);
    }
}

void func4(int cur, int cnt){
    visited[cur] = 1;
    
    if(cnt == m){
        for(int i=0; i<n; i++){
            if(visited[i])
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
    else{
        for(int i=cur+1; i<n; i++){
            func4(i, cnt + 1);
        }
    }
    
    visited[cur] = 0;
}

void func3(int num, int cnt){ // 1~n까지 중복불가능한 순서쌍
    visited[num] = 1;
    
    if(cnt == m){
        for(int i=1; i<=n; i++){
            if(visited[i])
                cout << i << " ";
        }
        cout << "\n";
    }
    else{
        for(int i=num+1; i<=n; i++){
            func3(i, cnt + 1);
        }
    }
    
    visited[num] = 0;
}

void func2(int cur){ // 1~n까지 중복불가능한 모든 순서쌍
    if(cur == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = 1;
            
            arr[cur] = i;
            func2(cur + 1);
            
            visited[i] = 0;
        }
    }
}

void func1(int cur){ // 1~n까지 중복가능한 모든 순서쌍
    if(cur == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i=1; i<=n; i++){
        arr[cur] = i;
        func1(cur + 1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> e;
        v.push_back(e);
    }
    
    sort(v.begin(), v.end());
    
    //func1(0);
    //func2(0);
    
//    for(int i=1; i<=n; i++)
//        func3(i, 1);
    
//    for(int i=0; i<n; i++)
//        func4(i, 1);
    
    //func5(0);
    func6(0);
    
    return 0;
}
