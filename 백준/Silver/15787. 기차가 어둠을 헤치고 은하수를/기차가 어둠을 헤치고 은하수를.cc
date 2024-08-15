#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void thirdIns(vector<bool> &one_train){
    for(int i=19; i>=1; i--){
        one_train[i] = one_train[i-1];
    }
    one_train[0] = false;
}

void fourthIns(vector<bool> &one_train){
    for(int i=0; i<=18; i++){
        one_train[i] = one_train[i+1];
    }
    one_train[19] = false;
}
/*
int canCrossMilkyWay(vector<vector<bool>> &train, int n){
    
    int cnt = 1;
    
    for(int i=1; i<n; i++){// 매 기차에 대해
    
        bool can_cross = true;  // 하나의 j라도 같으면 false
    
        for(int j=0; j<i; j++){ // 이전 기차를 확인
        
        bool is_in_history = true;
        
            for(int k=0; k<20; k++){ // 처음부터 끝자리까지 확인하면서
            
                if(train[i][k] != train[j][k]){ // i와 j의 좌석이 모두 똑같으면
                    // i는 기록에 있는 j와 똑같지 않음 
                    is_in_history = false;
                }
            }
            
            if(is_in_history){  // 기록에 있었던 것과 똑같으면
                can_cross = false;
            }
        }
        
        if(can_cross){
            cnt++;
        }
    }
    return cnt;
}
*/

int canCrossMilkyWay(vector<vector<bool>> &train, int n){
    unordered_set<size_t> seen;  // 해시값을 저장할 집합
    int cnt = 0;

    for(int i = 0; i < n; i++){
        size_t hash = 0;
        for(int k = 0; k < 20; k++){
            hash = hash * 2 + train[i][k]; // 좌석 배열을 해시로 변환
        }

        if(seen.find(hash) == seen.end()){ // 중복되지 않는 배열
            seen.insert(hash);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> train(n, vector<bool>(20,false));
    
    while(m--){
        
        int ins;
        cin >> ins;
        
        if(ins == 1 ){
            int i, x;
            cin >> i >> x;
            train[i-1][x-1] = true;
        }
        if(ins == 2){
            int i, x;
            cin >> i >> x;
            train[i-1][x-1] = false;
        }
        if(ins == 3){
            int i;
            cin >> i;
            thirdIns(train[i-1]);
        }
        if(ins == 4){
            int i;
            cin >> i;
            fourthIns(train[i-1]);
        }
    }
    
    cout << canCrossMilkyWay(train, n);

    return 0;
}