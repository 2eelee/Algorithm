#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const vector<int> normal_dir= {0,4,3,1,2};    // index: dir의 원소로 꺾이지 않는 경우의 다음 방향을 저장. 

int my_max(int a, int b, int c) {
    
    return max(max(a, b), c);
}

int detectConcave(vector<pair<int, int>>& input){
    
    int index, prev=input[5].first;
    
    for(int i=0; i<6; i++){
        
        if(input[i].first!=normal_dir[prev]){
            return i;
        }
        prev = input[i].first;
        
    }
}


int main()
{
    int k;
    cin >> k;
    
    vector<pair<int, int>> input(6);
    int dir, len;// 입력을 위해 변수 선언
    
    for(int i=0; i<6; i++){
        
        cin >> dir >> len ;
        input[i] = make_pair(dir, len);
        
    }
    
    int index = detectConcave(input);
    int prev_index=index-1;
    if(index==0){
        prev_index=5;
    }
    
    
    int max_dir1 = my_max(input[0].second, input[2].second, input[4].second);
    int max_dir2 = my_max(input[1].second, input[3].second, input[5].second);
    
    int min_dir1 = input[prev_index].second;
    int min_dir2 = input[index].second;
    
    //cout << max_dir1 << ' ' << max_dir2 << ' ';
    //cout << min_dir1 << ' ' << min_dir2 << ' ';
    
    
    int area = max_dir1 * max_dir2 - min_dir1 * min_dir2; // 참외밭의 넓이 구하기 
    
    cout << area * k << '\n';// 참외 생산량 출력 
    
    return 0;
}