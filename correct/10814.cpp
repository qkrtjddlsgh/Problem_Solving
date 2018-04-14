// 나이순 정렬
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct person {
    int age;
    int line;
    string name;
};

struct person arr[100001];

int main(int argc, char *argv[]){
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i].age >> arr[i].name;
        arr[i].line = i;
    }
    
    sort(arr, arr + n, [](person a, person b){
        if(a.age == b.age)
            return a.line < b.line;
        return a.age < b.age;
    });
    
    for(int i=0; i<n; i++)
        cout << arr[i].age << " " << arr[i].name << "\n";
    
    return 0;
}
