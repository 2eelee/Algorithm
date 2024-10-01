#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minS(int n, vector<int>& a, vector<int>& b){
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end());
    
    int s=0;
    
    for(int i=0; i<n; i++){
        s+=a[i]*b[i];
    }
    
    return s;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    
    cout << minS(n,a,b);
    
}