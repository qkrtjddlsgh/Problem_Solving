// 좋은 수열
#include <bits/stdc++.h>
using namespace std;

int n;

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    cin >> n;
    
    return 0;
}

 /* 2661 좋은수열
 - 1, 2, 3 순서대로 넣어보니까 처음 찾은게 제일 작은 수
 
 - 정수 -> 문자열 변환
 속도 비교
 http://hashcode.co.kr/questions/902/%EC%A0%95%EC%88%98%ED%98%95%EC%9D%84-%EB%AC%B8%EC%9E%90%EC%97%B4%EB%A1%9C-%EB%B3%80%ED%99%98%ED%95%A0-%EB%95%8C%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90
 여러가지 방법 비교
 https://code.i-harness.com/ko/q/2ed0d

#include<iostream>
using namespace std;

int N = 0;
string RESULT;
// string teststr = "";  // 전역변수 하면 왜 no symbol ???ㅠㅠㅠㅠㅠㅠ

bool is_good_sequence(string str){
    // cout << "\"" << str << "\" is good?" << endl;
    
    int i, ip, j, jp; // i, j : 비교할 첫 글자 위치 / ip, jp : 비교할 다음 글자
    bool is_good = true;
    
    if( str.length() == 0)
        return false;
    if( str.length() == 1)
        return true;
    if( str.length() == 2)
    {
        str[0] == str[1] ? is_good = false : is_good = true;
        return is_good;
    }
    
    for(i = 0; i < str.length() - 1 ; i++){
        for(j = i + 1; j < str.length(); j++){
            ip = i;
            jp = j;
            while(1){
                // printf("ip, jp : [%d] : %c / [%d] : %c\n", ip, str[ip], jp, str[jp]);
                if( str[ip] == str[jp] ){
                    if( jp - ip == 1 )  // 바로 옆 숫자. 같은 숫자 연달아 있는 경우.
                        return false;
                    
                    ip++; jp++; // 언제까지 같은지 보자
                    
                    if( ip == j ) // bad. 여태 비교한 문자 계속 같다가 ip, j 만남 // 121 122
                        return false;
                    
                    if( jp >= str.length() ){ // good. ip, j 만나기 전에 문자열 끝남
                        j = 88; // i++로 가야해..
                        break;
                    }
                    
                }else{  // 글자가 같지 않음
                    is_good = true;
                    break;  // j++로 감
                }
            }
        }
    }
    
    return is_good;
}

// 좋은 수열 되는 경우에만 호출
string append_number(string RESULT){
    
    int i;
    char tmp_char[2] = {0}; // 정수->문자열 변환용
    string tmp_result;
    int len = RESULT.length();  // 현재 문자열 길이
    
    // cout << "append_number : " << RESULT << " (" << len << ")" << endl;
    
    if( len >= N )
        return RESULT;
    
    for(i = 1; i <= 3; i++){  // 1,2,3 순서대로 넣어도 될지 확인해보고 append()
        tmp_char[0] = i + 48;
        if( RESULT[ RESULT.length()-1 ] == tmp_char[0] ) continue; // 바로 앞의 숫자는 제외
        tmp_result = RESULT;
        tmp_result.append(tmp_char);
        
        if( is_good_sequence(tmp_result) ){
            tmp_result = append_number(tmp_result);
            
            // cout << "tmp : " << tmp_result.length() << " / " << len << endl;
            if( tmp_result.length() == N ){
                // 답 찾아서 리턴된거. 이거 쭉 리턴해주면 됨
                RESULT = tmp_result;
                break;
            }
            
        }
        else if( i == 3 )  // 셋 다 좋은수열 아닌 경우
        {
            // cout << "no good seq" << endl;
            RESULT = "";
        }
    }
    
    // cout << "return RESULT : " << RESULT << endl;
    return RESULT;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    string RESULT = "1";
    RESULT = append_number(RESULT);
    cout << RESULT << endl;
    return 0;
} */
