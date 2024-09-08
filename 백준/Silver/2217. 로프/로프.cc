#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GreedySelector(vector<int>& rope, int k){
    
    int max_weight = 0;
    
    sort(rope.begin(), rope.end(), greater<int>());
    
    for(int i=0; i<k; i++){
        max_weight = max(max_weight, rope[i] * (i+1));
    }
    
    return max_weight;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    int n;
    cin >> n;
    
    vector<int> rope(n,0);
    
    for(int i=0; i<n; i++){
        cin>> rope[i];
    }
    
    cout << GreedySelector(rope, n);
    
    return 0;
    
}