#include<iostream>
using namespace std;

class Node{
    public:
        Node* prev;
        int data;
        Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

int lengthLL(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAthead(Node* &head ,Node* &tail, int data){
    Node* newnode = new Node(data);
    newnode->prev = NULL;
    if(head == NULL){
        newnode->next = NULL;
        tail = newnode;
    }else{
        newnode->next = head;
        head->prev = newnode;
        }
    head = newnode;
}

void insertAtTail(Node* &tail , Node* &head , int data){
    Node* newnode = new Node(data);
    newnode->next = NULL;
    if(tail == NULL){
        newnode->prev = NULL;
        head = newnode;}
    else{
        tail->next = newnode;
        newnode->prev = tail;}
    tail = newnode;
}

void insertAtPosition(int pos , int data , Node* &head , Node* &tail){
    Node* newnode = new Node(data);
    Node* temp = head;
    int cnt = 1 ;
    if(pos == 1){insertAthead(head,tail,data); return;}
    while(cnt < pos-1 ){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){insertAtTail(tail,head,data); return;}
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    temp=newnode->next;
    temp->prev = newnode;
    
}

void deleteNode(int pos , Node* &head , Node* & tail){
    Node* temp = head;
    if(pos == 1){
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        int cnt = 1;
        while(cnt < pos-1){
            temp = temp->next;
            cnt++;
        }
        Node* temp2 = temp->next;
        if(temp2->next == NULL){
            temp->next  = NULL;
            temp2->prev = NULL;
        }else{
        temp2->next->prev = temp->prev;
        temp->next = temp2->next;
        temp2->next = NULL;
        temp2->prev = NULL;
        }
        delete temp2;
    }

}

int main()
{
    Node* tail = NULL;
    Node* head = NULL;
    print(head);
    insertAthead(head , tail , 17);
    print(head);
    insertAthead(head , tail , 85);
    print(head);
    insertAthead(head , tail , 47);
    print(head);
    insertAthead(head , tail , 1);
    print(head);
    insertAtTail(tail , head , 69);
    print(head);
    insertAtPosition(6,15,head,tail);
    print(head);
    deleteNode(6,head,tail);
    print(head);


    return 0;
}