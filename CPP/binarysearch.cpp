#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int array[], int key ,int  n){
    int s =0 ; int e = n-1;
    int mid = (s + (e-s)/2);
    while (s<=e){

        if (array[mid] == key){     
            return mid;
        }else if(array[mid] < key){
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid = (s + (e-s)/2);
    }return -1;
}

int first_occourance(int arr[] , int key, int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int last_occourance(int array[] , int key, int size){
    int s =0 ; int e = size-1;
    int currentleft  = -1;

    
while (s<=e){  

    int mid = (s+e)/2;

    if (array[mid] == key){     
        currentleft = mid;
        s = mid+1;

    }else if(array[mid] < key){
        
        e=mid-1;
    }else{

        s=mid+1;
    }   
}return currentleft;
}

int mountailArrayPeakIndex(int array[] , int size){
    int s = 0 , e = size-1;
    int mid = s + (e - s)/2;

    while (s < e) {
        if (array[mid] < array[mid+1])
        {
            s = mid+1;
        }else{
            e=mid;
        }
        
        mid = s + (e-s)/2;
    }
    return s;
}



int main()
{
    int array[4] = {3,4,5,1};
    cout<<mountailArrayPeakIndex(array,4);
    return 0;
}