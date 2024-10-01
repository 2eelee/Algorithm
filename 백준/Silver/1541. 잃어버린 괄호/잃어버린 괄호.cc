#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void split(const string& str, char delimiter, vector<string>& result) {
    stringstream ss(str);
    string temp;
    
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
}

int main()
{
    string expression;
    cin >> expression;  // 수식 입력 받기

    vector<string> parts;
    // '-'로 수식을 나누기
    split(expression, '-', parts);

    int total = 0;
    
    for(int i=0; i<parts.size(); i++){
        int part_sum = 0;
        stringstream ss(parts[i]);
        string temp;
        
        // 각 부분을 '+'로 나누고 더함
        while (getline(ss, temp, '+')) {
            part_sum += stoi(temp);
        }
        
        // 첫 번째 부분은 total에 더하고, 나머지 부분은 빼기
        if (i == 0) {
            total += part_sum;
        } else {
            total -= part_sum;
        }
    }
    cout << total;
}