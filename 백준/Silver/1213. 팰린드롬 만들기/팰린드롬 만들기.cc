#include <iostream>
#include <vector>

using namespace std;

vector<int> readAlphabet(string& name) {
	vector<int> cnt(26,0);
	int len = name.length();
	for(int i=0; i<len; i++) {
		cnt[name[i]-'A']++;
	}
	return cnt;
}

string makePalindrome(vector<int>& cnt) {
	string str1="", str2="", str3="";
	for(int i=0; i<26; i++) {
		if(cnt[i]%2==1) {
			if(str2.length()==1) {
				return "I'm Sorry Hansoo";
			}
			else {
				str2=(char)(i+'A');
			}
		}
		for(int j=0; j<cnt[i]/2; j++) {
			str1+=(char)(i+'A');
			str3=(char)(i+'A')+str3;
		}
	}
	return str1 + str2 + str3;
}

string solution(string& name) {
	vector<int> cnt = readAlphabet(name);
	return makePalindrome(cnt);
}

int main()
{
	string name;
	cin >> name;
	cout << solution(name);
}