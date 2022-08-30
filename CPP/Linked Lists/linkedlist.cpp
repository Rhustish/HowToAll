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
};

void printCircular(Node* &tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}

void insertAtTail(Node* &tail , int newdata){

    if( tail == NULL) {
        Node* temp = new Node(newdata);
        tail = temp;
    }

    //new node creation
    Node* temp = new Node(newdata);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void insertattail2(Node* &head, Node* &tail, int data){

    Node* temp = new Node(data);

    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
    tail->next = temp;
    tail = temp;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl<<endl;
}

Node* reverse(Node* &head){
    //base
    if(head == NULL || head->next == NULL) return head;

    Node* restHead = reverse(head->next);
    head->next->next = head;

    head->next = NULL;
    return restHead;

}


Node* itoll(int n){
    Node* op = new Node(n%10);
    Node* tail = op;
    while(n > 0 ){
        insertAtTail(tail,n%10);
        n/=10;
    }
    return reverse(op);
}