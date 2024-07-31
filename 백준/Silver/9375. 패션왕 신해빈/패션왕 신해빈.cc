// https://www.acmicpc.net/problem/9375
// 의상의 이름과 의상의 종류 중 우리에게 필요한 입력값은 무엇일까요?
// 의상을 입지 않는 경우를 조심해야 할 것 같아요.

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--){    // 각 테스트별로(<=100) 경우의 수 출력
        
        int n;
        cin >> n;
        
        map<string, int> closet;
        
        auto insertOrUpdate = [&](string& key, int value) {
            
            auto result = closet.insert({key, value});
            
            if (!result.second) {
                result.first->second += value;
            }
        };
        
        while(n--){
            string name, type;
            cin >> name >> type;
            insertOrUpdate(type, 1);
        }
        
        int fashion_cnt=1;
        
        for(auto &itr : closet) {
            fashion_cnt *= (itr.second+1);
        }
        
        fashion_cnt-=1;
        cout << fashion_cnt << '\n';
    }
}