#include<iostream>
using namespace std;

//One based indexing
//child left = 2*i
//child right = 2*i + 1;
//parent = i/2

class Heap{
    public:
    int arr[100];
    int topidx = 0;

    void insertMax(int x){
        topidx++; int idx = topidx;
        arr[idx] = x;

        while(arr[idx] > arr[idx/2]  && idx != 1){
            swap(arr[idx] , arr[idx/2]);
            idx/=2;
        }
    }

    void deleteRoot(){
        if(!topidx)return;
        arr[1] = arr[topidx];
        int i = 1;
        topidx--;
        while(i < topidx){
            if(arr[i] < arr[2*i] && arr[i] > arr[2*i + 1]){
                swap(arr[i] , arr[2*i]);
                i*=2;
            }else if(arr[i] < arr[2*i + 1] && arr[i] > arr[2*i]){
                swap(arr[i] , arr[2*i + 1]);
                i = 2*i + 1;
            }else if(arr[i] < arr[2*i + 1] && arr[i] < arr[2*i]){
                int ni = arr[2*i] > arr[2*i + 1]    ? 2*i : 2*i + 1;
                swap(arr[i] , arr[ni]);
                i = ni;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1 ; i <= topidx ; i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
};