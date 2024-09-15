#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& edge, vector<bool>& visited, int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        int node_cnt = edge[cur].size();
        
        for(int i=0; i<node_cnt; i++){
            int now = edge[cur][i];
            
            if(!visited[now]){
                q.push(now);
                visited[now] = true;
            }
        }
    }
}

int cntConnectedComponent(vector<vector<int>>& edge, int n){
    vector<bool> visited(n + 1, false);  // 크기 n+1로 초기화
    int component_cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(edge, visited, i);
            component_cnt++;
        }
    }
    return component_cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edge(n+1);
    
    while(m--){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    cout << cntConnectedComponent(edge, n);
    
    return 0;
}