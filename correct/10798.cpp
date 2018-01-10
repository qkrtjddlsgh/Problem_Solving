// 세로읽기
#include <bits/stdc++.h>
using namespace std;

char word[5][15];

int main(int argc, char *argv[]){
    
    for(int i=0; i<5; i++)
        scanf("%s", word[i]);
    
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(word[j][i] == NULL)
                continue;
            else
                cout << word[j][i];
        }
    }
          
    cout << "\n";
    return 0;
}
