#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next=NULL;
        }

        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

void insertAtTail(Node* &tail , int newdata){

    //new node creation
    Node* temp = new Node(newdata);
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

bool detectLoop(Node* &head){
    //base call
    if(head == NULL) return 0;

    map<Node*,bool> visited;

    Node* temp = head;
    while(temp!=NULL){

        if(!visited[temp]){
            visited[temp] = 1;
            temp=temp->next;
        }else{
            cout<<"Loop present at "<<temp->data<<endl;
            return 1;
        }
    }
    return 0;
}   


Node* floydDetectLoop(Node* head) {                        //BABBAR BHAIYA

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* floydsCycleDetectionAlgo(Node* &head){   //MINE

    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast) return slow;
    }
    return NULL;
}

Node* loopStart(Node* head){                                 //MINE
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydsCycleDetectionAlgo(head);
    Node* slow = head;
    while(intersection != slow){
        slow = slow->next;
        intersection=intersection->next;
    }
    return slow;
}

Node* getStartingNode(Node* head) {                            //BABBAR BHAIYA

    if(head == NULL) 
        return NULL;

    Node* intersection = floydsCycleDetectionAlgo(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;
}

void removeLoop(Node* head){
    if(head == NULL) return;
    Node* core = loopStart(head);
    Node* temp = core;
    while(temp->next != core){
        temp = temp->next;
    }
    temp->next = NULL;
}


int main()
{
    Node* node1 = new Node(15);
    Node *head = node1;
    Node* tail = node1;
    insertAtTail(tail,13);
    insertAtTail(tail,14444444);
    insertAtTail(tail,33);
    insertAtTail(tail,17);
    insertAtTail(tail,23);
    insertAtTail(tail,19);
    insertAtTail(tail,99);
    insertAtTail(tail,76);
    insertAtTail(tail,456);
    insertAtTail(tail,144);
    insertAtTail(tail,155);
    insertAtTail(tail,34);
    tail->next = head->next->next;
    cout<<detectLoop(head)<<endl;
    removeLoop(head);
    cout<<detectLoop(head);
    return 0;
}