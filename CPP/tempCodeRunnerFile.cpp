#include<iostream>
#include<algorithm>
using namespace std;
void heapsort(int x[],int n){}
void makeheap(int x[],int n){}
int main()
{
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        int a[n], i = 0;
        
        for(int p = 0 ; p < n ; p++) cin>>a[p];sort(a,a+n);
        while(a[i] < x){
            x-=a[i];
            i++;
        }
        cout<<i<<endl;
        heapsort(a,n); 
        makeheap(a,n);
    }
    
    return 0;
}