#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(int n, const vector<vector<int>>& graph, int r) {
    vector<int> visit_num(n, 0);
    queue<int> pq;
    
    int cnt = 0;
    visit_num[r] = ++cnt;
    pq.push(r);
    
    while (!pq.empty()) {
        int x = pq.front();
        pq.pop();
        
        for (int v : graph[x]) {
            if (visit_num[v] == 0) {
                visit_num[v] = ++cnt;
                pq.push(v);
            }
        }
    }
    
    return visit_num;
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<vector<int>> graph(n);
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        // Convert 1-based to 0-based index
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Sort the adjacency lists to ensure the order in BFS
    for (int i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    
    vector<int> visit_num = bfs(n, graph, r - 1);
    for (int i = 0; i < n; ++i) {
        cout << visit_num[i] << '\n';
    }

    return 0;
}