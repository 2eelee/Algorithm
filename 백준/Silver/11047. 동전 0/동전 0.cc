#include <iostream>
#include <vector>

using namespace std;

int greedyCoinCnt(vector<int>& coin, int n, int k){
    
    int cnt=0;
    
    for(int i=n-1; i>=0; i--){
        int this_coin_cnt = k/coin[i];
        k -= this_coin_cnt * coin[i];
        cnt += this_coin_cnt;
        
        if(k==0){
            break;
        }
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> coin(n,0);
    
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
    
    cout << greedyCoinCnt(coin, n, k);
}