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
        if( this -> next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtTail(Node* &tail , int data){
    Node* newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}

void deleteNode(Node* &head, Node* &nodeToDelete){
    Node* temp = head;
    while(temp->next != nodeToDelete){
        temp = temp->next;
    }
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;
    delete nodeToDelete;
}

void removeDuplicateSorted(Node* &head ){
    Node* temp = head;
    while(temp != NULL){
        if((temp->next != NULL) && temp->data == temp->next->data){
            Node* temp2 = temp->next;
            deleteNode(head,temp2);
        }
        temp = temp -> next ;
    }
}

void unsorted(Node* &head){
    // AP1 = 2 loops 
    //AP2 = map
    //AP3 = sort karle
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl<<endl;
}

int main()
{
    Node* n1 = new Node(1);
    Node* head = n1;
    Node* tail = n1;
    insertAtTail(tail,12);
    insertAtTail(tail,14);
    insertAtTail(tail,14);
    insertAtTail(tail,155);
    removeDuplicateSorted(head);
    print(head);

    return 0;
}