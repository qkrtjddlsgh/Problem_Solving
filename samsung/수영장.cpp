// 수영장 : 수영장,퇴사문제의 특징 : 현재까지의 최소/최대값을 저장하면서 가야한다.
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int tc, ans, price[4], plan[15], dmonth[15], dp[15];

int main(int argc, char *argv[]){
    scanf("%d", &tc);
    
    for(int h=0; h<tc; h++){
        for(int i=0; i<4; i++)
            scanf("%d", &price[i]);
        for(int i=1; i<=12; i++)
            scanf("%d", &plan[i]);
        
        // 월간 최소값 저장
        for(int i=1; i<=12; i++)
            dmonth[i] = min(price[0] * plan[i], price[1]);
        
        for(int i=1; i<=12; i++){
            dp[i] = dp[i-1] + dmonth[i]; // 현재까지 최대값 저장
            
            if(i - 3 >= 0){
                if(dp[i] > dp[i-3] + price[2]){
                    dp[i] = dp[i-3] + price[2];
                }
            }
        }
        
        ans = min(dp[12], price[3]);
        printf("#%d %d\n", h+1, ans);
        
        memset(dmonth, 0, sizeof(dmonth));
        memset(dp, 0, sizeof(dp));
        ans = 0;
    }
    
    return 0;
}
