#include <stdio.h>

int main()
{   int tc;
    scanf("%d", &tc);
    for(int j=1; j<=tc; j++){
        
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        for(int k=1; k<=d; k++){
            
            int max= (a>b?a:b)>c?(a>b?a:b):c;
            if(max==a) a--;
            else if(max==b) b--;
            else if(max==c) c--;
            
            
        }
        
        printf("%d\n",a*b*c );
        
    }
}
