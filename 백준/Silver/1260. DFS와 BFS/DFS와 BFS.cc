#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(int n, vector<vector<int>>& edge, int v){
    
    vector<int> stack;
    vector<bool> visited(n,false);
    
    stack.push_back(v);
    visited[v] = true;
    cout << v << ' ';
    
    while(!stack.empty()){
        
        int current = stack.back();
        
        for(int i=1; i<=n; i++){
            
            if(edge[current][i] !=0 && !visited[i]){
                stack.push_back(i);
                visited[i] = true;
                cout << i << ' ';
                break;
            }
            else if(i==n-1){
                stack.pop_back();
            }
        }
        
    }
    
}

void BFS(int n, vector<vector<int>>& edge, int v){
    queue<int> q;
    vector<bool> visited(n,false);
    
    q.push(v);
    visited[v] = true;
    cout << v << ' ';
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(int i=1; i<=n; i++){
            
            if(edge[current][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(i);
                cout << i << ' ';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m, v;
    cin >> n >> m >> v;
    
    vector<vector<int>> edge(n+1, vector<int>(n+1,0));
    
    while(m--){
        int a, b;
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    
    DFS(n, edge, v);
    cout << '\n';
    BFS(n, edge, v);
    
    return 0;
}