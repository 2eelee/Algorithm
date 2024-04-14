#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_N = 8;

int n, m;
int sequence[MAX_N]; // 선택된 숫자 수열 저장용
int input[MAX_N];       

/**
 * 수열 출력 함수
*/
void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void printInput() {
    for (int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}

/**
 * 숫자를 하나 씩, 총 M개가 될 때까지 뽑는다(중복 가능).
 *
 * cnt: 현재까지 고른 숫자의 개수
*/
void backtrack(int cnt) {
    // M개의 숫자를 다 뽑은 경우 -> 결과 프린트 후 재귀 호출 종료
    if (cnt == m) {
        printSequence();
        return;
    }

    // i: 고르려는 수 (1~N 자연수), i를 1부터 순차적으로 탐색하므로 수열은 자동 오름차순 정렬된다.
    for (int i = 1; i <= n; i++) {

        // 선택한 숫자 기록
        sequence[cnt] = input[i-1];

        // 다음 숫자 고르기
        backtrack(cnt + 1);

        // 위의 백트래킹 재귀 호출 종료 시, 숫자 i 사용 완료 반납
    }
}

int main() {
    // 입력
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> input[i];
    }
    
    // 입력 받은 수에서 중복 제거
    sort(input, input + n);
    n = unique(input, input + n) - input;

    // 입력 받은 수를 정렬
    sort(input, input + n);
    

    // 백트래킹
    backtrack(0);

    return 0;
}