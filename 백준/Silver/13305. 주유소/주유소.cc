#include <iostream>
#include <vector>

using namespace std;

int minOilConst(int n, vector<int>& road_length, vector<int>& oil_cost){
    
    int total_cost = 0;
    int min_cost = oil_cost[0];
    
    for(int i=0; i<n-1; i++){
        total_cost += min_cost*road_length[i];
        
        if(oil_cost[i+1] < min_cost){
            min_cost = oil_cost[i+1];
            
        }
    }
    return total_cost;
}

int main()
{
    // 입출력 개선
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> road_length(n-1,0);     // 0~n-2번 도로의 길이
    vector<int> oil_cost(n,0);          // 0~n-1번 주유소의 기름값
    
    for(int i=0; i<n-1; i++){
        cin >> road_length[i];
    }
    for(int i=0; i<n; i++){
        cin >> oil_cost[i];
    }
    
    cout  << minOilConst(n, road_length, oil_cost);
}