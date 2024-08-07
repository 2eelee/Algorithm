#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> array(n+1,1);
    
    int cnt = 0;
    
    for(int i=2; i<=n;i++){
        
        if(array[i]==1){
            
            for(int p=i; p<=n; p+=i){
                
                if(array[p]==1){
                    array[p]=0;
                    cnt++;
                    if(cnt==k){
                        cout << p;
                    }
                }
            }
        }
    }

    return 0;
}