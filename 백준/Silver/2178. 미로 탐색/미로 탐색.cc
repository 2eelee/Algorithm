#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dist_bfs(vector<vector<int>>& maze, int n, int m){
    
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited 배열 초기화
    queue<pair<pair<int, int>, int>> q; // 위치와 함께 현재까지의 거리를 저장
    
    int x = 0, y = 0;
    
    visited[x][y] = true;
    q.push({{x, y}, 1}); // 시작점에서 거리는 1
    
    while(!q.empty()){
        
        auto pos = q.front();
        x = pos.first.first;
        y = pos.first.second;
        int dist = pos.second;
        q.pop();
        
        if(x == n-1 && y == m-1) { // 목표 지점에 도달했을 때 거리 반환
            return dist;
        }
        
        for(int i=0; i<4; i++){
            
            int temp_x = x + dx[i];
            int temp_y = y + dy[i];
            
            if(temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= m){
                continue;
            }
            
            if(!visited[temp_x][temp_y] && maze[temp_x][temp_y] == 1){
                visited[temp_x][temp_y] = true;
                q.push({{temp_x, temp_y}, dist + 1}); // 다음 지점으로 이동하면서 거리를 증가시킴
            }
        }
    }
    
    return -1; // 경로가 없을 경우 -1 반환
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> maze(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j] - '0';
        }
    }
    
    cout << dist_bfs(maze, n, m) << '\n';
    
    return 0;
}
