#include <iostream>
using namespace std;

// 조합을 직접 계산하는 함수 (팩토리얼을 사용하지 않고 더 효율적으로 계산)
long long comb(int m, int n) {
    if (n > m - n) n = m - n;  // C(m, n) == C(m, m-n), 더 작은 쪽으로 계산
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result *= (m - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int T;
    cin >> T;  // 테스트 케이스 개수 입력

    while (T--) {
        int N, M;
        cin >> N >> M;  // 서쪽 사이트 N, 동쪽 사이트 M 입력

        // C(M, N)을 계산하고 출력
        cout << comb(M, N) << endl;
    }

    return 0;
}
