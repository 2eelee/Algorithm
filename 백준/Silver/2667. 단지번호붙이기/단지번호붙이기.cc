#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 상, 하, 좌, 우 탐색을 위한 방향 배열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// BFS를 사용하여 단지 내 집의 수를 셈
int bfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int i, int j, int n) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int house_cnt = 1;

    while (!q.empty()) {
        auto [cur_x, cur_y] = q.front();  // 현재 좌표
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int new_x = cur_x + dx[dir];
            int new_y = cur_y + dy[dir];

            // 지도의 범위 내에 있고, 집이 있으며, 방문하지 않은 경우
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                if (map[new_x][new_y] == 1 && !visited[new_x][new_y]) {
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = true;
                    house_cnt++;
                }
            }
        }
    }
    return house_cnt;
}

// 모든 단지를 탐색하고, 각 단지의 집 수를 반환
vector<int> findComplexes(vector<vector<int>>& map, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<int> house_counts;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 집이 있고 방문하지 않은 경우
            if (map[i][j] == 1 && !visited[i][j]) {
                house_counts.push_back(bfs(map, visited, i, j, n));
            }
        }
    }
    return house_counts;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));

    // 한 줄씩 입력받고, 그 값을 map에 채워넣기
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;  // 한 줄의 숫자를 문자열로 받음
        for (int j = 0; j < n; j++) {
            map[i][j] = row[j] - '0';  // 문자열의 각 문자를 정수로 변환해서 map에 저장
        }
    }

    vector<int> house_counts = findComplexes(map, n);

    // 단지의 수 출력
    cout << house_counts.size() << '\n';

    // 각 단지의 집 수를 오름차순으로 정렬
    sort(house_counts.begin(), house_counts.end());

    // 단지 내 집 수 출력
    for (int count : house_counts) {
        cout << count << '\n';
    }

    return 0;
}
