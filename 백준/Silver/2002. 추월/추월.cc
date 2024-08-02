#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    map<string, int> car_input;
    vector<string> car_output(n);
    
    for(int i=0; i<n; i++){
        string car;
        cin >> car;
        car_input.insert({car,i});
    }
    
    for(int i=0; i<n; i++){
        cin >> car_output[i];
    }
    
    int cnt=0;
    
    for(int i=0; i<n-1; i++){
        
        for(int j=i+1; j<n; j++){
            
            if( car_input[car_output[i]] > car_input[car_output[j]] ){
               cnt++;
               break;
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}