// 일곱 난쟁이
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int sum, num[9], arr[9];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    for(int i=0; i<9; i++)
        cin >> arr[i];
    
    for(int i=0; i<9; i++){
        
        for(int a=0; a<9; a++)
            num[a] = arr[a];
        
        for(int j=0; j<9; j++){
            
            if(i == j)
                continue;
            
            int t1 = num[i];
            int t2 = num[j];
            
            num[i] = INF;
            num[j] = INF;
            
            for(int k=0; k<9; k++){
                if(num[k] != INF)
                    sum += num[k];
            }
            
            if(sum == 100){
                sort(num, num + 9);
                
                for(int k=0; k<7; k++)
                    cout << num[k] << "\n";
                
                return 0;
            }
            else
                sum = 0;
            
            num[i] = t1;
            num[j] = t2;
        }
    }
    
    return 0;
}
