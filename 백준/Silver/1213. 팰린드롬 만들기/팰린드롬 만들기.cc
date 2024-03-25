#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
const int NUM_CHARS = 26;

void countFreq(string word, vector<int> &freq) {
    
    for (int i = 0; i < word.length(); i++) {
        
        freq[word[i] - 'A']++; 
    }

}

string getString(vector<int>& freq) {
    string result;
    for (int i = 0; i < freq.size(); ++i) {
        
        if(freq[i]>=2){
            char ch = 'A' + i;                      // 해당 인덱스에 대응하는 알파벳
            result += string(freq[i]/2, ch);  
        }
    }
    return result;
}

bool checkPalindrome(vector<int> freq){
    
    bool flag = false;
    
    for(auto num:freq){
        num = num%2;
        
        if(num==1){
            
            if(flag==true){
                return false;
            }
            
            flag=true;
        }
        
    }
    return true;
}

int findOddFreqIndex(vector<int> freq){
    
    //freq는 팰린드롬 가능한 문자열의 알파벳 빈도 수를 저장한 vector임을 가정
    
    for (int i = 0; i < freq.size(); ++i) {
        
        freq[i] = freq[i]%2;
        
        if (freq[i] == 1) {
            return i; 
        }
    }
    
    return -1;
}

string reverseString(string& input) {
    string reversed;
    // 입력된 문자열을 끝에서부터 시작해서 거꾸로 저장
    for (int i = input.length() - 1; i >= 0; --i) {
        reversed.push_back(input[i]);
    }
    return reversed;
}

string makePalindrome(vector<int> freq){
    
    int index = findOddFreqIndex(freq);
    string word = getString(freq);
    string reverse = reverseString(word);
    
    if(index != -1){   // 짝수인 알파벳들로만 이뤄져 있는 경우 
        char odd_char = (char)(index+'A');
        word.push_back(odd_char);
        
        
    }
    
    return word+reverse;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string name;
    cin >> name;
    
    vector<int> name_freq(NUM_CHARS, 0);
    countFreq(name, name_freq);
    
    if(!checkPalindrome(name_freq)){
        cout << "I'm Sorry Hansoo"<<'\n';
        return 0;
    }
    
    //cout << (char)(( findOddFreqIndex(name_freq) )+'A');
    cout << makePalindrome(name_freq) << '\n';
    
}