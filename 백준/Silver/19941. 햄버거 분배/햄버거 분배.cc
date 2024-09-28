#include <iostream>
#include <vector>

using namespace std;

bool canEat(int start, int end, string& hamburger){
    for(int i=start; i<=end; i++){
        if(i>=0 && i<hamburger.length() && hamburger[i]=='H'){
            hamburger[i]='E';
            return true;
        }
    }
    return false;
}

int solution(int n, int k, string& hamburger) {
    int ans=0;
	for(int i=0; i<n; i++){
	    if(hamburger[i]!='P'){
	        continue;
	    }
	    if(canEat(i-k, i-1, hamburger)){
	        ans++;
	    }
	    else if(canEat(i+1, i+k, hamburger)){
	        ans++;
	    }
	}
	return ans;
}

int main()
{
	int n, k;
	cin >> n >> k;
	string hamburger;
	cin >> hamburger;
	
	cout << solution(n, k, hamburger);
}