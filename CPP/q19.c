#include<stdio.h>

int main(){
    int year;
    scanf("%d",&year);
    if(!(year%4)){
        printf("LEAP YEAR");
    }else{
        printf("NOT A LEAP YEAR");
    }
return 0;
}