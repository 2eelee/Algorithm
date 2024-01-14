#include <stdio.h>
int main(){
	int price, n, sum=0;
    
    scanf("%d\n%d", &price, &n);
    
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sum+=(a*b);
    }
    
    if(sum==price) printf("Yes");
    else printf("No");
}