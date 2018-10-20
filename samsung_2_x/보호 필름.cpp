// 보호 필름
#include <iostream>
using namespace std;

int tc, d, w, k, cnt, ans, visited[21], arr[21][21], map[21][21]; // AB : 01

void chk(){
    cnt = 0;
    
    for(int i=0; i<w; i++){
        for(int j=0; j<d; j++){
            // 처리
        }
    }
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;
    
    for(int t=1; t<=tc; t++){
        cin >> d >> w >> k;
        
        for(int i=0; i<d; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
                map[i][j] = arr[i][j];
            }
        }
        
        chk();
        
        if(cnt == w){
            cout << "0\n";
            return 0;
        }
        
        //for(int i=0; i<d; i++)
            //func(i, 1);
        
        cout << "#" << t << " " << ans << "\n";
    }
    
    return 0;
}
