#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int calMinCost(int n, vector<vector<int>>& field){
    
    int min=3000;
    
    for(int i=1; i<n-1; i++){   
        for(int j=1; j<n-1; j++){
            
            for(int k=1; k<n-1; k++){
                for(int l=1; l<n-1; l++){
                    
                    for(int m=1; m<n-1; m++){
                        for(int o=1; o<n-1; o++){
                            
                            int tmp_min;
                            
                            tmp_min = field[i][j] + field[i-1][j] + field[i+1][j] + field[i][j-1] + field[i][j+1];
                            tmp_min += field[k][l] + field[k-1][l] + field[k+1][l] + field[k][l-1] + field[k][l+1];
                            tmp_min += field[m][o] + field[m-1][o] + field[m+1][o] + field[m][o-1] + field[m][o+1];
                            
                            if( (abs(i-k) + abs(j-l) < 3) || (abs(i-m) + abs(j-o) < 3) || (abs(k-m) + abs(l-o) < 3) ){
                                break;
                            }
                            
                            if (tmp_min < min){
                                
                                min = tmp_min;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return min;
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> field(n, vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> field[i][j];
        }
    }
    
    cout << calMinCost(n, field);
    
    return 0;
}