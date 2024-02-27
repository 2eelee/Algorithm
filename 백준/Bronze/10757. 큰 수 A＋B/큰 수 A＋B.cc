#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> convertStringToInt(string input){ 
    
    vector<int> digits;

    for (char digitChar : input) {
        int digit = digitChar - '0';
        digits.push_back(digit);
    }
    
    return digits;
}

vector<int> convertIndexReverse(vector<int> &arr){
    
    int length = arr.size();
    vector<int> temp(length);
    
    for(int i=0; i<length; i++){
        temp[i] = arr[length-i];
    }
    
    return temp;
    
}

void addByDigit(vector<int> &num1, vector<int> &num2){
    
    int len1 = num1.size();
    int len2 = num2.size();
    
    int length = ((len1 > len2) ? len1 : len2) + 1;
    
    vector<int> result(length, 0);
	int carry = 0;

	for (int i = 0; i < length-1; i++) {
		int digit1 = (i < len1) ? (num1[len1 - 1 - i]) : 0;
		int digit2 = (i < len2) ? (num2[len2 - 1 - i]) : 0;

		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result[length - 1 - i] = (sum % 10);
	}

	if (carry > 0) {
		result[0] = carry;
	} 
			
	else {
		result.erase(result.begin());
	}
    
    for (int digit : result) {
        cout << digit;
    }
    
}

void add2BigInt(string input1, string input2){
    
    vector<int> digits1 = convertStringToInt(input1);
    vector<int> digits2 = convertStringToInt(input2);
    
    addByDigit(digits1, digits2);
    
}


int main() {
    string input1, input2;
    cin >> input1 >> input2;
    
    add2BigInt(input1, input2);

    return 0;
}
