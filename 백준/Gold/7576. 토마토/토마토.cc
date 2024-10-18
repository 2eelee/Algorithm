#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}; 

// 토마토가 익는 과정
void bfsRiping(int m, int n, vector<vector<int>>& tomatoes, queue<pair<int, int>>& q) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 범위 내에 있는지 확인하고 익지 않은 토마토(0)를 발견하면
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && tomatoes[nx][ny] == 0) {
                tomatoes[nx][ny] = tomatoes[x][y] + 1; // 익은 날짜를 기록
                q.push({nx, ny});
            }
        }
    }
}

// 최소 며칠이 걸리는지 계산하는 함수
int calMinDay(int m, int n, vector<vector<int>>& tomatoes) {
    int max_day = 0;  // 최대 일수를 기록할 변수
    
    // 토마토가 모두 익었는지 확인하면서 최댓값을 찾음
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 익지 않은 토마토가 있으면 -1 리턴
            if (tomatoes[i][j] == 0) {
                return -1;
            }
            // 토마토가 익는 데 걸린 최대 일수 확인
            max_day = max(max_day, tomatoes[i][j]);
        }
    }
    
    // 처음 시작이 1이므로 1일을 빼줌
    return max_day - 1;
}

int main()
{   
    // 입출력 개선
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> tomatoes(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomatoes[i][j];
        }    
    }
    
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomatoes[i][j] == 1) {
                q.push({i, j});  // 익은 토마토 위치를 큐에 저장
            }
        }
    }
    
    bfsRiping(m, n, tomatoes, q);
    
    cout << calMinDay(m, n, tomatoes);
}