#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<pair<int, int>> dot(n);
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        dot[i] = {a, b};
    }
    
    sort(dot.begin(), dot.end());
    
    for(int i=0; i<n; i++){
        cout << dot[i].first << ' ' << dot[i].second << '\n';
    }

    return 0;
}