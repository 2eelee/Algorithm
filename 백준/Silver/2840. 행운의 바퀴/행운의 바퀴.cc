#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<char> pan(n, '?');
    int index = 0;
    
    for(int i=0; i<k; i++){ // 둘째 줄부터 각각 s와 알파벳을 k회 입력 
        
        int s;
        char ch;
        cin >> s >> ch;
        
        index+=s;
        
        if(index>=n){       // index가 n을 넘어가지 않도록 조정 
            index=index%n;
        }
        
        if(pan[index]!='?'&&pan[index]!=ch){    // 
            cout << "!";
            return 0;
        }
        
        for(int j=0; j<n; j++){
            
            if(pan[j]==ch){
                
                if(j==index) continue;
                
                else {
                    cout << "!";
                    return 0;
                }
            }
        }
        
        pan[index] = ch;
    }
    
    for(int i=0; i<n; i++){
        cout << pan[index];
        index--;
        if(index<0) index = n-1;
    }
}
