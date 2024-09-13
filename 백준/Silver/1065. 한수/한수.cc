#include <iostream>
#include <cmath>

using namespace std;

bool checkHansu(int a){
    
    if (a < 100) {
        return true;  // 1~99는 모두 한수
    }

    int last_digit = a % 10;
    a /= 10;
    int middle_digit = a % 10;
    int gap = middle_digit - last_digit; // 첫 두 자리의 차이 계산

    while (a >= 10) {
        last_digit = middle_digit;
        a /= 10;
        middle_digit = a % 10;
        if (middle_digit - last_digit != gap) {
            return false;
        }
    }
    
    return true;
}

int cntHansu(int n){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if (checkHansu(i)){
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    cout << cntHansu(n);
}