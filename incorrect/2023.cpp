// 신기한 소수
#include <iostream>
using namespace std;

int n;

bool isPrime(int num){
    for(int i=2; i<=num; i++){
        if(num % i == 0)
            return false;
    }
    
    return true;
}

int main(int argc, char *argv[]){
    scanf("%d", &n);
    
    
    
    return 0;
}
