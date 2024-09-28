#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    int n = friends.size();
    map<string, int> friends_dict;
    for(int i=0; i<n; i++){
        friends_dict[friends[i]]=i;
    }
    
    vector<vector<int>> gift_array(n,vector<int>(n,0));
    vector<int> gift_score(n,0);
    vector<int> total_gift(n,0);
    
    for(string gift: gifts){
        string a, b;
        stringstream ss(gift);
        ss >> a >> b;
        
        gift_array[friends_dict[a]][friends_dict[b]]++;
        gift_score[friends_dict[a]]++;
        gift_score[friends_dict[b]]--;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(gift_array[i][j] > gift_array[j][i]){
                total_gift[i]++;
            }
            else if(gift_array[i][j] == gift_array[j][i]){
                if(gift_score[i]>gift_score[j]){
                    total_gift[i]++;
                }
            }
        }
    }
    
    int max_gift = total_gift[0];
    for(int i=1; i<n; i++){
        if(total_gift[i] > max_gift){
            max_gift = total_gift[i];
        }
    }
    
    
    return max_gift;
}