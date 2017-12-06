// 상수
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n1, n2;
    string temp1, temp2;
    scanf("%d %d", &n1, &n2);
    
    temp1 = to_string(n1);
    reverse(temp1.begin(), temp1.end());
    
    temp2 = to_string(n2);
    reverse(temp2.begin(), temp2.end());
    
    if(temp1 > temp2)
        cout << temp1 << "\n";
    else
        cout << temp2 << "\n";
    
    return 0;
}

