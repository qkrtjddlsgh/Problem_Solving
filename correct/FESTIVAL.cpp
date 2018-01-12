// FESTIVAL
#include <stdio.h>
using namespace std;

int n, l;
int cost[1001];

double ans = 987654321, avg, sum;

int main(int argc, char *argv[]) {
    int tc;
    scanf("%d", &tc);
    
    while (tc--) {
        scanf("%d %d", &n, &l);
        
        for (int i = 1; i <= n; i++)
            scanf("%d", &cost[i]);
        
        while (l <= n) {
            
            for (int i = 1; i <= n - l + 1; i++) {
                sum = 0;
                
                for (int j = i; j < i + l; j++) {
                    sum += cost[j];
                }
                
                avg = sum / l;
                
                if (avg < ans)
                    ans = avg;
            }
            
            l++;
        }
        
        printf("%.11f\n", ans);
        ans = 987654321;
    }
    
    return 0;
}
