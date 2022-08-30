#include<iostream>
#include<map>
using namespace std;
//clone ll with random pointers
class Node{
  public:
    int data;
    Node* next;
    Node* random;  

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }

};

void insertAtTail(Node* &head, Node* &tail, Node* temp){

    if(head == NULL){
        head = temp;
        tail = temp;
        tail->next = NULL;
    }

    tail->next = temp;
    tail = temp;
}

Node* cloneMap(Node* head){
    //creating a new ll
    Node* nhead = NULL;
    Node* ntail = nhead;
    //creating an iterator and storage map
    map<Node* , Node*> ref;
    Node* temp = head;
    //copying ll
    while(temp != NULL){
        Node* newNode = new Node(temp->data);
        insertAtTail(nhead,ntail,newNode);
        ref[temp] = newNode;
        temp = temp->next;
    }

    temp = head;
    Node* ntemp = nhead;
    while(temp != NULL && ntemp != NULL){
        ntemp->random = ref[temp->random];
        temp = temp -> next;
        ntemp = ntemp -> next;
    }
    return nhead;
}



int main()
{
    /* code */
    return 0;
}
