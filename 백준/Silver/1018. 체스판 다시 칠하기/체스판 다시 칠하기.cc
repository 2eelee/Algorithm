#include <iostream>
#include <algorithm>
using namespace std;

// 특정 8x8 부분 보드를 체스판 패턴과 비교하여 다시 칠해야 하는 칸의 개수를 계산하는 함수
int calculateRepaints(char board[50][50], int startX, int startY) {
    int repaint1 = 0, repaint2 = 0;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            // 패턴 1: (x + y) % 2 == 0 인 경우 'W', 아닌 경우 'B'
            if ((x + y) % 2 == 0) {
                if (board[startX + x][startY + y] != 'W') repaint1++;
                if (board[startX + x][startY + y] != 'B') repaint2++;
            } else {
                if (board[startX + x][startY + y] != 'B') repaint1++;
                if (board[startX + x][startY + y] != 'W') repaint2++;
            }
        }
    }

    // 두 패턴 중 더 적게 다시 칠해야 하는 횟수를 반환
    return min(repaint1, repaint2);
}

// 보드 전체를 순회하며 8x8 부분 보드를 찾고, 그중 최소 칠하기 횟수를 찾는 함수
int findMinimumRepaints(char board[50][50], int N, int M) {
    int minRepaints = 64;  // 8x8 체스판에서 최대 64개의 칸이므로 초기값을 64로 설정

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            minRepaints = min(minRepaints, calculateRepaints(board, i, j));
        }
    }

    return minRepaints;
}

int main() {
    int N, M;
    cin >> N >> M;

    char board[50][50];

    // 보드 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 최소 다시 칠해야 하는 칸의 수 계산
    int result = findMinimumRepaints(board, N, M);

    // 결과 출력
    cout << result << endl;

    return 0;
}
