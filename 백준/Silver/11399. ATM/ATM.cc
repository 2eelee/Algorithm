#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& p, int n){
    sort(p.begin(), p.end());
    
    int ans = 0, prev = 0;
    for(int i=0; i<n; i++){
        prev+=p[i];
        ans+=prev;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> p(n,0);
    
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    
    cout << solution(p, n);
}