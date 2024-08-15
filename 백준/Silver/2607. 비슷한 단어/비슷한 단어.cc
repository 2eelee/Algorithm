#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isSameComposition(vector<char> &first_comp, vector<char> &second_comp){
    
    for(int i=0; i<26; i++){
        if(first_comp[i] != second_comp[i]){
            return false;
        }
    }
    return true;
}

bool isSimilar(string& first, string& second){ // first와 other가 비슷한 문자열이면 true

    vector<char> first_comp(26,0);
    vector<char> second_comp(26,0);
    
    for(int i=0; i<first.size(); i++){
        first_comp[first[i]-'A']++;
    }
    
    for(int i=0; i<second.size(); i++){
        second_comp[second[i]-'A']++;
    }
    
    if(isSameComposition(first_comp, second_comp)){
        return true;
    }
    
    for(int i=0; i<26; i++){
        second_comp[i]++;
        if(isSameComposition(first_comp, second_comp)){
            return true;
        }
        second_comp[i]--;
    }
    
    for(int i=0; i<26; i++){
        second_comp[i]--;
        if(isSameComposition(first_comp, second_comp)){
            return true;
        }
        second_comp[i]++;
    }
    
    for(int i=0; i<26; i++){
        
        if(second_comp[i]>0){
            
            second_comp[i]--;
            
            for(int j=0; j<26; j++){
                
                if(i==j) {
                    continue;
                }
                
                second_comp[j]++;
                
                if(isSameComposition(first_comp, second_comp)){
                    return true;
                }
                
                second_comp[j]--;
            }
            
            second_comp[i]++;
        }
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int num;
    cin >> num;
    
    string first;
    cin >> first;
    
    num--;
    
    int cnt = 0;
    
    while(num--){
        string other;
        cin >> other;
        
        if(isSimilar(first, other)){
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}