#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int height = board.size();
    int moves_cnt = moves.size();
    stack<int> basket;
    
    for(int i=0; i<moves_cnt; i++){
        int pos = moves[i]-1;
        for(int j=0; j<height; j++){
            
            if(!board[j][pos]){
                continue;
            }
            int doll = board[j][pos];
            board[j][pos]=0;
            if(!basket.empty() && basket.top() == doll){
                basket.pop();
                answer+=2;
            }
            else{
                basket.push(doll);
            }
            break;
            }
    }    
    return answer;
}