#include<iostream>
#include"linkedlist.cpp"
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node* &tail , int element , int data){
    Node* newnode = new Node(data);
    if(tail == NULL){
        tail = newnode;
        newnode->next=newnode;
    }else{
        Node* temp = tail;
        while(temp->data != element){
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void printCircular(Node* &tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}



int main(){

    Node* tail = NULL;
    insert(tail,5,3);
    insert(tail,3,5);
    insert(tail,5,15);
    insert(tail,15,9);
    insert(tail,9,90);
    insert(tail,90,99);
    insert(tail,99,69);
    insert(tail,69,16);
    insert(tail,16,64);
    print(tail);
    // cout<<tail->data<<endl;
    // halfLists(tail);
    return 0;
}
    