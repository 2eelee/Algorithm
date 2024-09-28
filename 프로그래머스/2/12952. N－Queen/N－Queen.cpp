#include <string>
#include <vector>

using namespace std;

int backtracking(int row, int n, vector<bool>& columns, vector<bool>& diag_up, vector<bool>& diag_down ){
    
    if(row==n){
        return 1;
    }
    
    int answers = 0;
    for(int col=0; col<n; col++){
        if( columns[col] || diag_up[row+col] || diag_down[row-col+n-1]){
            continue;
        }
        
        columns[col] = true;
        diag_up[row+col] = true;
        diag_down[row-col+n-1] = true;
        
        answers += backtracking(row+1, n, columns, diag_up, diag_down);
        
        columns[col] = false;
        diag_up[row+col] = false;
        diag_down[row-col+n-1] = false;
    }
    return answers;
}

int solution(int n) {
    vector<bool> columns(n,false);
    vector<bool> diag_up(2*n-1, false);
    vector<bool> diag_down(2*n-1, false);
    
    return backtracking(0, n, columns, diag_up, diag_down);
}