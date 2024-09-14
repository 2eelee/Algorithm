#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int N, int K) {
    vector<int> visited(100001, -1);  // 방문 여부와 시간을 기록하는 배열
    queue<int> q;  // BFS를 위한 큐
    
    // 수빈이의 시작 위치
    visited[N] = 0;
    q.push(N);
    
    // BFS 수행
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        // 동생을 찾으면 반환
        if (current == K) {
            return visited[current];
        }
        
        // 이동할 수 있는 3가지 경우
        int next_positions[3] = {current - 1, current + 1, current * 2};
        
        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];
            
            // 이동 가능한 범위 내에서, 아직 방문하지 않은 위치만 큐에 추가
            if (next >= 0 && next <= 100000 && visited[next] == -1) {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }
    
    return -1;  // 이 코드는 절대 실행되지 않음. 문제 조건에 의해 항상 답이 존재함.
}

int main() {
    int N, K;
    cin >> N >> K;
    
    // 결과 출력
    cout << bfs(N, K) << endl;
    
    return 0;
}
