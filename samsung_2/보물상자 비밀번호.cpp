// 보물상자 비밀번호
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int tc, n, k, ans, cnt; char arr[30];

vector <int> v;

void rotate_right(){
    char temp = arr[n-1];
    
    for(int i=n-1; i>0; i--)
        arr[i] = arr[i-1];
    
    arr[0] = temp;
}

void binary_to_decimal(int start, int end){
    int sum = 0;
    int idx = 0;
    
    for(int i=end; i>=start; i--){
        int temp = arr[i];
        
        if(temp == 'A')
            temp -= 55;
        else if(temp == 'B')
            temp -= 55;
        else if(temp == 'C')
            temp -= 55;
        else if(temp == 'D')
            temp -= 55;
        else if(temp == 'E')
            temp -= 55;
        else if(temp == 'F')
            temp -= 55;
        else
            temp -= 48;
        
        sum += (temp * pow(16, idx));
        idx++;
    }
    
    int chk = 0;
    
    for(int i=0; i<v.size(); i++){
        if(sum == v[i])
            chk = 1;
    }
    
    if(chk == 0)
        v.push_back(sum);
}

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> tc;

    for(int t=1; t<=tc; t++){
        cin >> n >> k;

        cnt = n / 4;

        for(int i=0; i<n; i++)
            cin >> arr[i];

        for(int i=0; i<cnt; i++){
            for(int h=0; h<4; h++)
                binary_to_decimal(cnt*h, cnt*(h+1)-1);

            rotate_right();
        }
    
        sort(v.begin(), v.end(), greater<int>());
    
        cout << "#" << t << " " << v[k-1] << "\n";
        v.clear();
    }
    
    return 0;
}

