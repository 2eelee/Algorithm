#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int cnt[100001] = {0};

int getLongest(vector<int>& a, int k){
    
    int p1 = 0, p2 = 0, max_length = 0;
    int array_size = a.size();
    
    while(p1<array_size){
        
        if( cnt[a[p1]] >= k ){   // 이번원소가 k+1번째 등장하는 경우 
            cnt[a[p2]]--;
            p2++;
        }
        else{
            cnt[a[p1]]++;
            p1++;
        }
        max_length = max(max_length, p1-p2 );
    }
    return max_length;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    
    for(int i=0; i<n; i++){ // 길이가 n인 수열 a에 입력(index: 0 ~ n-1)
        cin >> a[i];
    }
    
    cout << getLongest(a, k);
}