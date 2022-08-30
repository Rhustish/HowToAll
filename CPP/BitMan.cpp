#include <iostream>
using namespace std;

bool getBit(int n, int p){       
    return (n & (1<<p))?1:0;
}

int setBit(int n , int p){
    return (n | (1<<p));
}

int clearBit(int n , int p ){
    return (n  & (~(1<<p)));
}

int updateBit(int n , int p , int v){

    n = clearBit(n,p);

    return  (n |(v<<p));
}


