// 공약수
#include <bits/stdc++.h>
using namespace std;

int arr[3];

int gcd(int a, int b){
    if(a < b)
        return gcd(b, a);
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    if(n == 2){
        int gcd1 = gcd(arr[0], arr[1]);
        
        for(int i=1; i<=gcd1; i++)
            if(gcd1%i == 0)
                printf("%d\n", i);
    }
    else{
        int gcd1 = gcd(arr[0], arr[1]);
        int gcd2 = gcd(arr[1], arr[2]);
        gcd1 = gcd(gcd1, gcd2);
        
        for(int i=1; i<=gcd1; i++)
            if(gcd1%i == 0)
                printf("%d\n", i);
    }
    
    return 0;
}
