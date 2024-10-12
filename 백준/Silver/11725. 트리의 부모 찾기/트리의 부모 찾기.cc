#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int n, vector<vector<int>>& tree, vector<int>& visited){
    int root = 1;
    queue<int> q;
    visited[root] = 0;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : tree[cur]) {
            if (visited[next] == -1) {
                q.push(next);
                visited[next] = cur;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    vector<int> visited(n + 1, -1);
    dfs(n, tree, visited);
    for (int i = 2; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}
