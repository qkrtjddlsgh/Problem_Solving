// 퇴사 : input이 적으므로 완전탐색을 통해 풀이
#include <iostream>
#include <algorithm>
using namespace std;

int n, sum, ans;
pair <int, int> arr[16];

void func(int cur, int sum) {
    // n+1일이면 종료
    if (cur == n + 1) {
        ans = max(ans, sum);
        return;
    }
    
    // 선택하지않고 넘어가는 경우
    func(cur + 1, sum);
    
    // 갈수있는 경우
    if (cur + arr[cur].first <= n + 1)
        func(cur + arr[cur].first, sum + arr[cur].second);
}

int main(int argc, char *argv[]) {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    
    func(1, 0);
    
    cout << ans << "\n";
    return 0;
}
