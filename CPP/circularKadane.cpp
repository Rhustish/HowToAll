#include <iostream>
using namespace std;

int kadane(int arr[],int n)
{
    int currSum = INT_MIN;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum+=arr[i];
        maxSum = max(maxSum,currSum);

        if (currSum <0)
        {
            currSum = 0;
        }
        
    }
    return maxSum;
    
}



int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int nonWrapSum = kadane(a,n);
    int totalsum;

    for (int i = 0; i < n; i++)
    {
        totalsum = a[i];    
        a[i] = -a[i];

    }
     
    int wrapsum =  kadane(a,n);

    cout<< max(nonWrapSum,totalsum+wrapsum);

    return 0;
}
