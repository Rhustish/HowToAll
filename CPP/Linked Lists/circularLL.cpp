#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
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

void print(Node* &tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}

void deletenode(int data , Node* &tail){
    if(tail == NULL){
        cout<<"empty list"<<endl;
        return;
    }
    if(tail->next == tail){
        tail->next = NULL;
        delete tail;
    }
    Node* temp = tail;
    while(temp->next->data != data){
        temp=temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
    if(tail == temp2) tail = temp; //IMPORTATNT FOR EDGE CASE
    delete temp2;
}

int main()
{
    Node* tail = NULL;

    insert(tail,5 , 3);
    print(tail);
    insert(tail,3,5);
    print(tail);
    insert(tail,5,15);
    print(tail);
    insert(tail,15,9 );
    print(tail);
    deletenode(3,tail);
    print(tail);
    return 0;
}