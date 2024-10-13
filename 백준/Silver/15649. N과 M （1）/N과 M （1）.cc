#include <iostream>
#include <vector>

using namespace std;

void backtracking(int n, int m, vector<int>& current, vector<bool>& visited){
    if(current.size()==m){
        for(int i=0; i<m; i++){
            cout << current[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            current.push_back(i);
            backtracking(n,m,current,visited);
            visited[i] = false;
            current.pop_back();
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n+1, false);
    vector<int> current;
    backtracking(n,m,current,visited);
    
}