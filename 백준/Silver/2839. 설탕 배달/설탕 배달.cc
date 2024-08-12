#include <iostream>

using namespace std;

int calBag(int n){
    
    int cnt=-1;
    
    for(int i=0; i<=n/5; i++){
        int sum=0;
        if((n-i*5)%3==0){
            int a = (n-i*5)/3;
            cnt = a+i;
        }
        else{
            continue;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    cout << calBag(n);

    return 0;
}