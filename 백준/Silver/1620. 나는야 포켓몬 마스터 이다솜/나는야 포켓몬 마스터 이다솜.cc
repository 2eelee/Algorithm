#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool is_digit(string str){
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    map<int, string> pokemonByNumber;
    map<string, int> pokemonByName;
    
    for(int i = 1; i <= n; i++){
        string input;
        cin >> input;
        pokemonByNumber.insert({i, input});
        pokemonByName.insert({input, i});
    }
    
    while(m--){
        string input;
        cin >> input;
        
        if(is_digit(input)){    // 숫자가 들어오면
            cout << pokemonByNumber[atoi(input.c_str())] <<  '\n';
        } else {                // 이름이 들어오면
            cout << pokemonByName[input] << '\n';
        }
    }
    
    return 0;
}
