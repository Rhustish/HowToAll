#include<iostream>
#include"linkedlist.cpp"
using namespace std;

//iterative approach

Node* loopReverse(Node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//recursive approach 1 !!!!!!!!

void recursiveReverse(Node* &head , Node* &curr , Node* &prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }
    
    //recursive logic
    Node* next = curr->next;
    recursiveReverse(head,next,curr);
    curr->next = prev;
    
}


