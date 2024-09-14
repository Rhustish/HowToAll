#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next=nullptr;
        }

        ~Node(){
            int value = this->data;
            if(this->next != nullptr){
                delete next;
                this->next = nullptr;
            }
        }
};

void insertAtHead(Node* &head , int newdata){

    //new node creation
    Node* node2 = new Node(newdata);
    node2->next = head;
    head = node2;
}

void insertAtTail(Node* &tail , int newdata){

    //new node creation
    Node* temp = new Node(newdata);
    tail->next = temp;
    temp->next = nullptr;
    tail = temp;
}

void insertInBetween(Node* &head, Node* &tail,int pos , int data){

    Node* newnode = new Node(data);
    Node* temp = head;
    int counter = 1;
    while(counter < pos-1){
        temp = temp->next;
        counter++;
    }
    if(temp->next == nullptr){
        insertAtTail(tail,data);
    }
    newnode->next = temp->next;
    temp->next = newnode;
    
}

void deleteNode(Node* &head , int pos){

    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
    Node* temp = head;
    int cnt = 1 ;
    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = nullptr;
    delete temp2;
    
}

void print(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertInBetween(head,tail,3,32);
    print(head);

    deleteNode(head,4);
    print(head);
    
    return 0;
}