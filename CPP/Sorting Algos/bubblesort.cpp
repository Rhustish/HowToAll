#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    for (size_t i = 0; i < n; i++)
    {
        bool swapped = 0; // for optimisation
        for (size_t j = 0; j < n-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped=1;
            }
        }
        if (!swapped)       //for aptimisation
        {
            break;
        }
        
    }
    
}

//best case complexity = O(n)
//worst case complexity = O(n^2)