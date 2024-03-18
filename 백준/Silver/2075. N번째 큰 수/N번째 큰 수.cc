#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int> > number;
    
    for(int i=0; i<n*n; i++){
        
        int input;
        cin >> input;
        number.push(input);
        
        if(number.size()>n){
            number.pop();
        }
    }
    
    cout << number.top();
}