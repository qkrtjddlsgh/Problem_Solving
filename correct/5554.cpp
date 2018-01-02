// 심부름 가는 길
#include <bits/stdc++.h>
using namespace std;

int sum, temp;

int main(int argc, char *argv[]){
    
    for(int i=0; i<4; i++){
        scanf("%d", &temp);
        sum += temp;
    }
    
    cout << sum / 60 << "\n" << sum % 60 << "\n";
    return 0;
}
