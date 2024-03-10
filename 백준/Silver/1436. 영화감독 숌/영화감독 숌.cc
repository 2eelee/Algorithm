#include <iostream>
#include <vector>

using namespace std;


int find666(int n){
    
    vector<int> arr;    // 666이 들어간 수를 저장하는 벡터 생성
    
    int a = 0;
    
    while(arr.size() != n){
        
        int tmp = a;
        
        while(tmp){
            
            if(tmp%1000 == 666){
                arr.push_back(a);
                break;
            }
            else{
                tmp/=10;
            }
            
        }
        a++;
    }
    
    return arr.back();
}

int main()
{
    int n;
    cin >> n;
    
    cout << find666(n);
    
    return 0;
}