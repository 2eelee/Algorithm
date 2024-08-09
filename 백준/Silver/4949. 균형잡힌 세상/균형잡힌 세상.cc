#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool balanced(string line){
    
    stack<char> brackets;

    for(char c: line){
        
        if(c=='.'){
            break;
        }
        if( c=='[' || c=='(' ){
            brackets.push(c);
        }
        else if( c==']' || c==')' ){
            
            if(brackets.empty()){
                return false;
            }
            
            char top = brackets.top();
            
            if( top=='[' && c==']' || top=='(' && c==')' ){
                brackets.pop();
            }
            else{
                return false;
            }
        }
    }
    
    if(brackets.empty()){
        return true;
    }
    
    else{
        return false;
    }
}

int main() {
    string line;

    while (true) {
        
        getline(cin, line); 
        
        if (line == ".") {
            break;
        }
        
        if(balanced(line)){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
    
    return 0;
}