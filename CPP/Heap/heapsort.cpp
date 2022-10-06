#include "heapify.cpp"
#include <queue>

void heapSort(int a[] , int n){
    while(n>=1){
        swap(a[1],a[n]);
        n--;
        heapify(a,n,1);
    }
}

int main(){
    int a[6] = {-1 , 70 , 60 , 55 , 45 , 50};
    Heap h ;
    h.insertMax(70);
    h.insertMax(60);
    h.insertMax(55);
    h.insertMax(45);
    h.insertMax(50);
    h.print();
    cout<<endl;

    //MAXHEAP using priority queue
    priority_queue<int> pq;
    pq.push(70);
    pq.push(60);
    pq.push(55);
    pq.push(45);
    pq.push(50);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;


}