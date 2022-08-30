#include<iostream>
using namespace std;

// int partition(int a[], int l , int h){
//     int pivot = a[l];
//     int i = l , j = h;

    
//     while (i<j) {
//             while (a[i] <= pivot &&  i<=h-1)
//                 i++;
//             while (a[j] > pivot && j>=l)
//                 j--;
//             if (i<j)
//                 swap(a[i],a[j]);
//         }


//     swap(a[j], a[l]);
//     return j;
// }

// void quicksort(int a[] , int l , int h){
//     if(l<h){
//         int pivot = partition(a,l,h);
//         quicksort(a,l,pivot-1);
//         quicksort(a,pivot+1,h);
//     }
// }




















int part(int a[] , int l , int h){
    int pivot = a[l];
    int i = l;
    int j = h;

    while(i<j){
        while(a[i] <= pivot && i <= h-1){
            i++;
        }
        while(a[j] > pivot && j >= l){
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    swap(a[j],a[l]);
    return j;
}

void quicksort(int a[] , int l , int h){
    if(l<h){
        int pivot = part(a,l,h);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,h);
    }
}

int main()
{
    int a[] = {3,5,23,5,6,7,24};
    quicksort(a,0,6);
    for(auto i : a){cout<<i<<endl;}
    
    return 0;
}