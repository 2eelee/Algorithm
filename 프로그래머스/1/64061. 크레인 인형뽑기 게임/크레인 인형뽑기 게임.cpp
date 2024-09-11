#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> basket;
    int move_cnt = moves.size();
    
    for(int i=0; i<move_cnt; i++){
        // board[][moves[i]-1] 뽑기
        
        // 알맞은 인형 집어서 바구니에 넣기
        int depth = board.size();
        for(int j=0; j<depth; j++){
            if(board[j][moves[i]-1] != 0){ // 가장 위에 있는 인형 찾았으면
                basket.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        
        // 인형이 같은 모양이면 터뜨리기
        if (basket[basket.size() - 1] == basket[basket.size() - 2]){
            basket.pop_back();
            basket.pop_back();
            answer+=2;
        }
    }
    
    return answer;
}