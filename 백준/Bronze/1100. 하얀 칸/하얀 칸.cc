#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    char pan[9][9];
    
    for(int i=0; i<8; i++){
        
        char line[9];
        cin >> line;
        
        for(int j=0; j<8; j++){
            pan[i][j] = (line[j]);
        }
    }
    
    int cnt = 0;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            
            if ( ( (i+j)%2 ==0 ) && (pan[i][j] == 'F') ) {
                cnt++;
            }
        }
    }
    
    cout << cnt;
}
