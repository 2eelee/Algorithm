#include <stdio.h>
int main(){
    int p;
    scanf("%d", &p);
    int a=p;
    int cnt;
    for(cnt=1;cnt <= 100;cnt++){
        int orgr = a%10;
        if(a<10) a*=10;
        int x=a/10, y=a%10;
        int hap=(x+y)%10;
        a=hap+(10*orgr);
        if(a==p) break;
    }
    printf("%d", cnt);
}