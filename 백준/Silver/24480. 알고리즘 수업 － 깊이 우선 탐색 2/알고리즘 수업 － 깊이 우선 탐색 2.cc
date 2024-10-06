#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int R, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order, int& cnt) {
    visited[R] = true;      // 시작 정점 R을 방문했다고 표시
    order[R] = ++cnt;       // 방문 순서를 기록
    
    // 정점 R에 인접한 정점들을 내림차순으로 탐색
    for (int x : adj[R]) {
        if (!visited[x]) {
            dfs(x, adj, visited, order, cnt);
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;  // 정점의 수 N, 간선의 수 M, 시작 정점 R 입력

    vector<vector<int>> adj(N + 1);  // 인접 리스트
    vector<bool> visited(N + 1, false);  // 방문 여부를 저장하는 배열
    vector<int> order(N + 1, 0);         // 각 정점의 방문 순서를 저장하는 배열
    int cnt = 0;  // 방문 순서를 기록하기 위한 카운터

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // 무향 그래프이므로 양방향 간선 추가
    }

    // 인접 리스트에서 각 정점의 인접한 정점들을 내림차순으로 정렬
    for (int i = 1; i <= N; i++) {
        sort(adj[i].rbegin(), adj[i].rend());
    }

    // DFS 탐색 시작
    dfs(R, adj, visited, order, cnt);

    // 방문 순서 출력
    for (int i = 1; i <= N; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}
