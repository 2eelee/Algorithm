#include <iostream>
#include <string>

using namespace std;

void add(int &set, int x){       
    set |= (1<<x);
}

void remove(int &set, int x){
    set &= ~(1<<x);
}

int check(int &set, int x){
    
    if( ( set & (1<<x) )!= 0){
        return 1;
    }
    else{
        return 0;
    }
}

void toggle(int &set, int x){
    
    if( ( set & (1<<x) )!= 0){
        set &= ~(1<<x);
    }
    else{
        set |= (1<<x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m;
    cin >> m;
    
    int set=0;
    
    while(m--){
        
        string ins;
        int x;
        
        cin >> ins;
        
        if(ins=="all"){
            set = ((1 << 21) - 1);
        }
        else if(ins=="empty"){
            set = 0;
        }
        
        else{
            cin >> x;
            
            if(ins=="add"){
                add(set, x);
            }
            else if(ins=="remove"){
                remove(set, x);
            }
            else if(ins=="check"){
                cout << check(set, x) << '\n';
            }
            else if(ins=="toggle"){
                toggle(set, x);
            }
        }
        
    }

    return 0;
}