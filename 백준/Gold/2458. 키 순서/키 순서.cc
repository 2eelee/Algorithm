#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000;

void floydWarshall(int n, vector<vector<int>> &graph) {
    
    for (int k = 1; k <= n; k++) { // 중간 정점
    
        for (int i = 1; i <= n; i++) { // 출발 정점
        
            for (int j = 1; j <= n; j++) { // 도착 정점
            
                int cost = graph[i][k] + graph[k][j];
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

bool checkStudent(int k, int n, vector<vector<int>> &graph){
    
    for (int i = 1; i <= n; i++) {
        if (i != k && graph[k][i] == INF && graph[i][k] == INF) {
            return false;
        }
    }
    return true;
}

int main() {
    
    int n, m, a, b;

    cin >> n >> m;
    
    vector<vector<int>> graph( n + 1, vector<int>(n + 1, INF) );
    
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    
    while (m--) {
        cin >> a >> b;
        graph[a][b] = 1;
    }

    floydWarshall(n, graph);
    
    int cnt = 0;
    
    for(int i=1; i<=n; i++){
        if(checkStudent(i, n, graph)){
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}