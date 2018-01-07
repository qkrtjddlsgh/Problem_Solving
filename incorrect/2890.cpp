// 카약
#include <bits/stdc++.h>
using namespace std;

int r, c;
char temp;
vector <pair<char, int>> ans;

int main(int argc, char *argv[]){
    scanf("%d %d", &r, &c);
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%c", &temp);
            
            if(temp == 'S' || temp == '.' || temp == 'F')
                continue;
            else{
                ans.push_back(make_pair(temp, c-1-j));
                cout << temp << " " << c-1-j << "\n";
                break;
            }
            
        }
    }
    
    return 0;
}
