#include<iostream>
#include<vector>
// #include<queue>
using namespace std;

class Queue{
    int* arr;
    int size;
    int front;
    int rear;

    Queue(){
        this->size = 100001;
        arr = new int[size];
        this -> front = 0;
        this -> rear = 0;
    }
    public:

    bool isEmpty(){
        if(front == rear) return 1;
        return 0;
    }

    void push( int data){
        if (rear == size){
            cout<<"Queue is full"<<endl;
        }else{
            arr[rear++] = data;
        }
    }

    void pop(){
        if (front == rear) return ;
        else{
            arr[front++] = -1;
        }

        if(front == rear) {
            front == 0 ;
            rear == 0;
        }
    }

    int frontD(){
        if(!this->isEmpty()){
            return arr[front];
        }else return -1;
    }
};

int main()
{
    
    return 0;
}