#include <iostream>
#include <set>
#include <string>

using namespace std;

int checkString(string input, set<string> &s) {
    int checkCnt = 0; 
    
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        string currentString = *iter;
        int len = input.length();
        
        if (currentString.length() < len) {
               continue; // 길이가 짧으면 다음 문자열로 건너뜁니다.
        }
        
        for (int i = 0; i <= currentString.length() - len; i++) {
            string subString = currentString.substr(i, len);
            
            
            if (!input.compare(subString)) // 두 문자열이 같을 때
                checkCnt++;
        }
    }
    
    return checkCnt;
}


int main(){
	
    int n, m;
    cin >> n >> m;
    
    set<string> s;
    string input;
    
    for(int i=0; i<n; i++){
        cin >> input;
        s.insert(input);
    }
    
    int checkCnt=0;
    
    for(int i=0; i<m; i++){
        cin >> input;
        if(s.find(input) != s.end()) checkCnt++;
    }
    
    cout << checkCnt << "\n";
    
}