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

void insertAtTail(Node* &tail , int newdata){

    //new node creation
    Node* temp = new Node(newdata);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

int getlength(Node* head){
    int c = 0;
    while(head != NULL){
        c++;
        head=head->next;
    }
    return c;
}
 
Node *findMiddle(Node *head) {
    int len = getlength(head);
    int mid = len/2 + 1;
    for(int i = 1 ; i < mid ; i++){
        head=head->next;
    }
    return head;

}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl<<endl;
}

int main(){

    Node* node1 = new Node(1);
    Node* tail= node1;
    Node* head = node1;
    
    // insertAtTail(tail,13);
    // insertAtTail(tail,12);
    // insertAtTail(tail,34);
    // insertAtTail(tail,76);
    // insertAtTail(tail,5);
    // insertAtTail(tail,55);
    // insertAtTail(tail,23);
    // insertAtTail(tail,66);
    // insertAtTail(tail,234);
    print(head);


    cout<<findMiddle(head) -> data << endl;

    return 0;
}