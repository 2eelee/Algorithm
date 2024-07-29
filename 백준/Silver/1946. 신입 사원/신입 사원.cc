#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    
    int tc;
    cin >> tc;
    
    while(tc--){
        int num;
        cin >> num;
        
        vector<pair<int,int>> score(num);
        
        for(int i = 0; i < num; i++){
            int a, b;
            cin >> a >> b;
            score[i] = {a, b};
        }
        
        // Sort by the first element (resume rank)
        sort(score.begin(), score.end());
        
        // Determine the maximum number of recruitable applicants
        int scoutable = 0, min_interview_rank = num + 1;
        
        for(int i = 0; i < num; i++){
            if(score[i].second < min_interview_rank){
                min_interview_rank = score[i].second;
                scoutable++;
            }
        }
        
        cout << scoutable << '\n';
    }
    
    return 0;
}
