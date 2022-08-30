#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cin>>n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }


// Brute force approach O(n^3)

    // int maxSum;
    
    // for (int i = 0; i < n; i++){
    //     for (int j = i; j < n; j++) {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++){
    //             sum+=a[k];
    //         }
    //         maxSum = max(maxSum,sum);
    //     }
    // }

    // cout<<maxSum;

// Kadane's Algo

    int currSum = INT_MIN;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum+=a[i];
        maxSum = max(maxSum,currSum);

        if (currSum <0)
        {
            currSum = 0;
        }
        
    }
    cout<<maxSum;

    return 0;
}
