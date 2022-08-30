#include <iostream>
#include <algorithm>
using namespace std;

int po2(int a[], int n , int k){
    sort(a,a+n);
    int p = 0 , q = n-1 ;
    int count = 0;
    while(p<=q){
        if(a[p] + a[q] < k ){
            p++;
            continue;
        }else if (a[p] + a[q] > k)
        {
            q--;
            continue;
        }else if (a[p] + a[q] == k){
        }
        {
            count++;
            p++;
        }
        
        
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int arr[4] = {1,5,7,1};
    cout<<po2(arr,4,6);
    
    return 0;
}