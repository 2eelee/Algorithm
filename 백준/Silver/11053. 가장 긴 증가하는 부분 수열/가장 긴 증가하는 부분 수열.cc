#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int max_num = 0;
    
    vector<int> arr(n, 0);
    vector<int> dp(n, 1);
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<i; j++){
            
            if(arr[i]>arr[j]){
                dp[i] = ( (dp[i] > (dp[j]+1) )? dp[i] : (dp[j]+1) );
            }
        }
        
        if(max_num <= dp[i]){
            max_num = dp[i];
        }
    }
    
    cout << max_num << '\n';
}