#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int i, int j, vector<vector<int>>& ground, vector<vector<bool>>& visited) {
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int temp_x = i + dx[k];
        int temp_y = j + dy[k];

        // 배열 경계 체크
        if (temp_x >= 0 && temp_x < ground.size() && temp_y >= 0 && temp_y < ground[0].size()) {
            // 아직 방문하지 않은 배추가 있다면
            if (!visited[temp_x][temp_y] && ground[temp_x][temp_y] == 1) {
                dfs(temp_x, temp_y, ground, visited);
            }
        }
    }
}

int worm_cnt(int n, int m, vector<vector<int>>& ground) {
    int cnt = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));  // 올바른 초기화

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && ground[i][j] == 1) {
                dfs(i, j, ground, visited);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<int>> ground(n, vector<int>(m, 0));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            ground[y][x] = 1;  // 주어진 입력에 맞게 x와 y 순서 반대로 설정
        }

        cout << worm_cnt(n, m, ground) << '\n';
    }

    return 0;
}
