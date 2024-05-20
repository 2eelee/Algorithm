#include <iostream>
#include <map>
#include <vector>

using namespace std;

void dfs(int node, int parent, map<int, vector<int>>& tree, vector<vector<int>>& adj, vector<int>& node_cnt) {
    
    node_cnt[node] = 1; // 자기 자신을 포함하므로 초기값을 1로 설정
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue; // 부모 노드로 돌아가는 것을 방지
        tree[node].push_back(neighbor); // 자식 노드 추가
        dfs(neighbor, node, tree, adj, node_cnt); // 자식 노드로 DFS 재귀 호출
        node_cnt[node] += node_cnt[neighbor]; // 자식 노드의 서브트리 크기를 더함
    }
}



int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
    int n, r, q;
    cin >> n >> r >> q;
    
    map<int, vector<int>> tree; // 정점 n개, 간선 n-1개
    vector<vector<int>> adj(n + 1); // 인접 리스트 선언
    vector<int> node_cnt(n, 0);
    
    for(int i=0; i<n-1; i++){
        
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    // 루트 노드에서 시작하여 트리 구성
    int root = r; // 루트 노드를 1로 가정
    dfs(root, -1, tree, adj, node_cnt); // DFS를 통해 트리 구성
    
    
    while(q--){
        
        int query_root;
        cin >> root;
        cout<< node_cnt[root] << '\n';
        
    }
}
