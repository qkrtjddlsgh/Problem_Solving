// 수 뒤집기
#include <bits/stdc++.h>
using namespace std;

char str[10001];
char cmp[10001];
char res[10001];

int main(int argc, char *argv[]){
    int tc;
    scanf("%d", &tc);
    
    while(tc--){
        scanf("%s", str);
        
        int start = 0, idx = 0; bool chk = false;
        unsigned long end = strlen(str);
        
        while(end--){
            res[idx] = cmp[start] + str[end-1];
            start++; end--; idx++;
        }
        
        for(int i=0; i<idx; i++){
            cmp[i] = res[i];
        }
        
        reverse(res, res+idx);
        
        for(int i=0; i<idx; i++){
            if(cmp[i] != res[i]){
                chk = true;
                break;
            }
        }
        
        if(chk)
            printf("NO\n");
        else
            printf("YES\n");
    }
    
    return 0;
}
