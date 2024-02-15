#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;  // n은 4 이상 1,000,000 이하
  
  vector<int> geummin;
  
  for(int i=4; i<=n; i++){
      
      int c=i;
      
      while(true){ //모든 자리수가 4나 7로 이루어져 있는지 확인
                    // c가 4또는 7이 되면 금민수로 인정
          
          if( (c%10!=4) && (c%10!=7) ) break;
          
          else{
              if(c<10){
                geummin.push_back(i);
                break;
              }
              c/=10;
           }
          
        }
      
    }
  
  cout << geummin[geummin.size()-1];
    
}
