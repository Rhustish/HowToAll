#include <iostream>
#include <C:\Users\Bhavy\Documents\VSCode files\CPP\BitMan.cpp>
using namespace std;

bool ip2(int n){

    if(n!=0){
    return (!(n&(n-1)));}
    else{
    return 0;
    }

}

int nofones(int n){

    int i = 0;
    while(n>0){
        n = n & n-1;
        i++;
    }
    return i ;
}   

void subset(int arr[] , int n){
    
    for (int i = 0; i < (1<<n) ; i++)
    {
        for (int j = 0; j < n; j++)    
        {
            if(getBit(i,j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
    
}

int main(){

    int arr[3] = {1,2,3};
    subset(arr,3);

    return 0;

}