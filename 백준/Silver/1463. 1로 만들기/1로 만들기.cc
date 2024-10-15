#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCalDP(int n){
    vector<int> dp(n+1);
    dp[1] = 0;
    
    for(int i=2; i<=n; i++){
        int tmin = dp[i-1] + 1;  // 기본적으로 1을 뺀 경우를 초기값으로 설정
        
        if(i % 3 == 0) {
            tmin = min(tmin, dp[i/3] + 1);  // 3으로 나눌 수 있으면 비교
        }
        if(i % 2 == 0) {
            tmin = min(tmin, dp[i/2] + 1);  // 2로 나눌 수 있으면 비교
        }
        
        dp[i] = tmin;  // 최솟값 갱신
    }
    
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    
    cout << minCalDP(n);
    
    return 0;
}
