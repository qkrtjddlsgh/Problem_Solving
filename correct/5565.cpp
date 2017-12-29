// 영수증
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    int total, total2 = 0;
    scanf("%d", &total);
    
    for(int i=0; i<9; i++){
        int temp;
        scanf("%d", &temp);
        total2 += temp;
    }
    
    cout << total - total2 << "\n";
    return 0;
}
