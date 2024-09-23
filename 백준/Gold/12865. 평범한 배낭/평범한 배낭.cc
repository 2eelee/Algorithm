#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxValueKnapsack(int n, int k, vector<pair<int,int>>& item){
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));
    
    for(int i=1; i<=n; i++){
        int weight = item[i-1].first;
        int value = item[i-1].second;
        
        for(int w=0; w<=k; w++){
            if(weight <= w){
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight]+value);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<pair<int,int>> item(n);
    
    for(int i=0; i<n; i++){
        cin >> item[i].first >> item[i].second;
    }
    
    cout << maxValueKnapsack(n, k, item);
}