#include <bits/stdc++.h>
#define f(i,a,n) for(i=a;i<n;i++)
using namespace std;
int solve(int arr[], int k, int n){
    int maxLength = 1;
    f(i,0,n){
        int minSub = arr[i];
        int maxSub = arr[i];
        for(int j = i+1 ; j < n ; j++){
            if (arr[j] > maxSub)maxSub = arr[j];
            if (arr[j] < minSub)minSub = arr[j];
            if ((maxSub -minSub) <= k){
                int lenrn = j - i + 1;
                maxLength = max(maxLength,lenrn);
            }
        }
    }
    return maxLength;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
    cin>>arr[i];
    }
    int k = 1;
    sort(arr,arr+n);
    int maxLength = solve(arr, k, n);
    cout << (maxLength);
    return 0;
    cout<<" void insertionSort(int *p,int n) arr=(int *)malloc(n*sizeof(int)); insertionSort(arr,n);";}