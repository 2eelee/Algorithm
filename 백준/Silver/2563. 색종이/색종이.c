#include <stdio.h>

int main()
{
    int arr[100][100]={0};
    
    int num;
    scanf("%d", &num);
    
    for(int t=0;t<num;t++){
        
        int x, y;
        scanf("%d %d", &x, &y);
        
        for(int i=x; i<=x+9; i++){
            for(int j=y; j<=y+9; j++){
                
                arr[i][j]=1;
            }
        }
        
    }
    
    int cnt=0;
    
    for(int i=0; i<100; i++){
        for(int j=0;j<100;j++){
            
            if(arr[i][j]==1) cnt++;
        }
    }
    
    printf("%d", cnt);
}

/* 반례
input:
4
1 1
1 11
11 1
11 11
output: 403
answer: 400
*/
