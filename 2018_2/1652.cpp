#include <iostream>
using namespace std;

int n, row, col;
char arr[101][101];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == '.' && j < n-1){
                if(arr[i][j+1] == '.'){
                    while(j < n && arr[i][j+2] == '.'){
                        j += 1;
                    }
                    row++;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j][i] == '.' && j < n-1){
                if(arr[j+1][i] == '.'){
                    while(j < n && arr[j+2][i] == '.'){
                        j += 1;
                    }
                    col++;
                }
            }
        }
    }
    
    cout << row << " " << col << "\n";
    return 0;
}
