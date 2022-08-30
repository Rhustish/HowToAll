#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int mos = n%8;
    if(mos == 4 )
        printf("%dLB",n-3);
    else if(mos == 5)
        printf("%dMB",n-3);
    else if(mos == 6 )
        printf("%dUB",n-3);
    else if (mos == 1)
        printf("%dLB",n+3);
    else if (mos == 2)
        printf("%dMB",n+3);
    else if (mos == 3)
        printf("%dUB",n+3);
    else if(mos == 7 )
        printf("%dSL",n-3);
    else if(mos == 8)
        printf("%dSU",n-3);
return 0;
}