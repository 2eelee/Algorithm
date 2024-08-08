#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comp(pair<int, int> &a, pair<int, int> &b) {
    
    if(a.second == b.second){
        return a.first < b.first;
    }
	return a.second < b.second;
}

int GreedyActivitySelector(vector<pair<int, int>> &activity, int n){
    
    int processor, cnt=1;
    processor = activity[0].second;
    
    for(int i=1; i<n; i++){
        
        if(activity[i].first >= processor){
            processor=activity[i].second;
            cnt++;
        }
    }
    
    return cnt;
}


int main()
{
    int ac_num;
    vector<pair<int, int>> activity;
    
    cin >> ac_num;
    
    for(int i=0; i<ac_num; i++){
        int start, finish;
        cin >> start >> finish;
        activity.push_back(make_pair(start, finish));
    }
    
    sort(activity.begin(), activity.end(), comp);
    
    int proc_num = GreedyActivitySelector(activity, ac_num);
    
    cout << proc_num;
}