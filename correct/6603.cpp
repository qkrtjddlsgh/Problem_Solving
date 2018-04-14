// 로또
#include <bits/stdc++.h>
using namespace std;

int k, arr[13], ans[13];

// 6개일때 종료
void chk(int index, int count){
    if(count == 6){
        for(int i=0; i<6; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    
    if(index == k)
        return;
    
    for(int i=index; i<k; i++){
        ans[count] = arr[i];
        chk(i+1, count+1);
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    do {
        cin >> k;
        
        for(int i=0; i<k; i++)
            cin >> arr[i];
        
        chk(0, 0);
        cout << "\n";
        
    } while(k != 0);
    
    return 0;
}
