#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; 

vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    
    vector<int> dist(v + 1, INF); 
    priority_queue<ci, vector<ci>, greater<>> pq; 

    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        
        int w_time = pq.top().first; 
        int node = pq.top().second; 
        pq.pop();

        if (w_time < dist[node]) { 
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            
            int next_node = graph[node][i].first;
            int next_w_time = w_time + graph[node][i].second;
            
            if (next_w_time < dist[next_node]) { 
                
                dist[next_node] = next_w_time;
                pq.push({next_w_time, next_node});
            }
        }
    }
    return dist;
}

int main() {
    
    int n, m, x, a, b, t;
    
    cin >> n >> m >> x;
    
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); 
    
    while(m--){
        cin >> a >> b >> t;
        graph[a].push_back({b, t}); 
    }
    
    vector<int> dist = dijkstra(x, n, graph);
    
    int max = 0;

    for (int i = 1; i <= n; i++) {
        
        vector<int> time_toGO = dijkstra(i,n,graph);
        
        if( (time_toGO[x] + dist[i] ) > max) {
            max = dist[i]+time_toGO[x];
        }
    }
    
    cout << max;
    
    return 0;
}
