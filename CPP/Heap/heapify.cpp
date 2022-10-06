#include "heap.cpp"

void heapify(int arr[] , int n , int i){
    int largest = i , left = 2*i , right = 2*i+1;
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n  && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest] , arr[i]);
         heapify(arr , n , largest);
    }
}
