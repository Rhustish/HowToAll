#include<iostream>
using namespace std;

// void merge(int arr[] ,int l , int mid ,  int r){

//     int n1 = mid-l +1;
//     int n2 = r-mid;
//     int a[n1];
//     int b[n2];

//     for(int i = 0 ; i < n1 ; i++){
//         a[i] = arr[l+i];
//     }
//     for(int i = 0 ; i < n2 ; i++){
//         b[i] = arr[mid+1 + i];
//     }

//     int i = 0;
//     int j = 0;
//     int k = l;

//     while(i < n1 && j < n2){
//         if(a[i]  <  b[j]){
//             arr[k] = a[i];
//             i++; k++;
//         }else{
//             arr[k] = b[j];
//             j++; k++;
//         }
//     }
//     while(i<n1){
//         arr[k] = a[i];
//         i++; k++;
//     }
//     while(j<n2){
//         arr[k] = b[j];
//         j++; k++;
//     }

// }


// void mergesort(int a[] , int s , int e){
//     if(s<e){
//         int mid = (s+e)/2;
//         mergesort(a,s,mid);
//         mergesort(a,mid+1,e);
//         merge(a,s,mid,e);
//     }
// }

 

void merge(int arr[] , int l , int mid , int r){

    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];

    for(int i = 0 ; i < n1 ; i++){
        a[i] = arr[l+i];
    }
    for(int i = 0 ; i < n2 ; i++){
        b[i] = arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }else{
            arr[k++] = b[j++];
        }
    }

    while(i < n1){
        arr[k++] = a[i++];
    }
    while(j < n2){
        arr[k++] = b[j++];
    }
}

void mergesort(int a[], int s , int e){
    if(s<e){
        int mid = (s+e)/2;
        mergesort(a , s , mid);
        mergesort(a , mid+1 , e);
        merge(a , s , mid , e);
    }
}

int main()
{
    int arr[] = {3435,232,3,2,1};
    mergesort(arr,0,4);

    for(auto i : arr){
        cout<<i<<endl;
    }
    return 0;
}