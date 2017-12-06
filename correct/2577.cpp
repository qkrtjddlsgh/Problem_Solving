// 숫자의 개수
#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main(int argc, char *argv[]){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    
    int prod = a*b*c;
    string str = to_string(prod);
    
    for(unsigned long i=0; i<str.length(); i++){
        if(str[i] == '0')
            cnt[0]++;
        else if(str[i] == '1')
            cnt[1]++;
        else if(str[i] == '2')
            cnt[2]++;
        else if(str[i] == '3')
            cnt[3]++;
        else if(str[i] == '4')
            cnt[4]++;
        else if(str[i] == '5')
            cnt[5]++;
        else if(str[i] == '6')
            cnt[6]++;
        else if(str[i] == '7')
            cnt[7]++;
        else if(str[i] == '8')
            cnt[8]++;
        else if(str[i] == '9')
            cnt[9]++;
    }
    
    for(int i=0; i<10; i++)
        printf("%d\n", cnt[i]);
    
    return 0;
}
