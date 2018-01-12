// BOGGLE
#include <bits/stdc++.h>
using namespace std;

int n;
char gnd[5][5];
char word[10][10];

int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};

bool hasWord(int x, int y, char find[]){
    return false;
}

int main(int argc, char *argv[]){
    int tc;
    scanf("%d", &tc);
    
    while(tc--){
        
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                scanf(" %c", &gnd[i][j]);
        
        scanf("%d", &n);
        
        for(int i=0; i<n; i++)
            scanf("%s", word[i]);
        
        for(int i=0; i<n; i++)
            hasWord(0, 0, word[i]);
    }
    
    return 0;
}
