#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedyMinTime(vector<int>& time, int n){
    
    int cumulated_time = 0, min_time = 0;
    
    sort(time.begin(), time.end());
    
    vector<int> wait_time(n,0);
    
    for(int i=0; i<n; i++){
        cumulated_time += time[i];
        wait_time[i] = cumulated_time;
    }
    
    for(int i=0; i<n; i++){
        min_time +=wait_time[i];
    }
    
    return min_time;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> time(n,0);
    
    for(int i=0; i<n; i++){
        cin >> time[i];
    }
    
    cout << greedyMinTime(time, n);
    
}