// 곱셈
#include <bits/stdc++.h>
using namespace std;

int num1;
char s[3];

int main(int argc, char *argv[]){
    scanf("%d %s", &num1, s);
    
    cout << num1 * (s[2]-48) << "\n";
    cout << num1 * (s[1]-48) << "\n";
    cout << num1 * (s[0]-48) << "\n";
    cout << num1 * (s[2]-48) + num1 * (s[1]-48) * 10 + num1 * (s[0]-48) * 100 << "\n";
    
    return 0;
}
