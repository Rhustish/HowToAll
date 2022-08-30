// APPROACH 2 OUTPUT INCORRECT

#include<iostream>
#include<map>
#include"linkedlist.cpp"
using namespace std;

//Approach1 counting all 012s
void count012s(Node* &head){
    int counter[3] = {0};
    Node* temp = head;
    while(temp != NULL){
        counter[temp->data]++;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < counter[i] ; j++){
            temp->data = i;
            temp = temp->next;
        }
    }
}

//Approach2 Data replacement not allowed (CHANGE LINKS NOT POINTS) Making 3 different lists for 012 and merging them at the end
//we will have to make 3 DUMMY NODES to avoid a lot of conditioning in while merging

void populate(Node* &tail , Node* & currnode){//Auxilary function for solving the question

    tail->next = currnode;
    currnode->next = NULL;
    tail = currnode;

}

void lists012(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* trav = head;
    while(trav != NULL){
        int currVal = trav->data;
        switch (currVal){
        case 0:
            populate(zeroTail,trav);
            break;
        case 1:
            populate(oneTail,trav);
        case 2:
            populate(twoTail,trav);
        default:
            break;
        }

        trav=trav->next;
    }

    //merging 3 sublists

    if(oneHead-> next != NULL){
        zeroTail->next = oneHead->next;
        oneTail = twoHead -> next;
    }else{
        zeroTail = twoHead->next;
    }
    twoTail->next = NULL;
    head = zeroHead->next;

    //deltedummy
    delete zeroHead;
    delete oneHead;
    delete twoHead;

}


int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail,1);
    insertAtTail(tail,0);
    insertAtTail(tail,0);
    insertAtTail(tail,1);
    insertAtTail(tail,2);
    
    insertAtTail(tail,2);
    insertAtTail(tail,0);
    insertAtTail(tail,2);
    insertAtTail(tail,1);
    print(head);
    lists012(head);
    print(head);

    return 0;
}