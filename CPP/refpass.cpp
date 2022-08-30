#include<iostream>
using namespace std;

void swapOld(int* a , int* b){ //works in c and cpp
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapNew(int& a , int& b){ // works in cpp only
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 5 , b = 6;
    swapOld(&a,&b);
    cout<<a<<b<<endl;
    swapNew(a,b);
    cout<<a<<b<<endl;
    return 0;
}