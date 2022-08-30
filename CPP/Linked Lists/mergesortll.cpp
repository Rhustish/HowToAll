#include<iostream>
#include "linkedlist.cpp"
using namespace std;

Node* middle(Node* &head){
    Node* slow = head , *fast = head->next;
    while(fast -> next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow; 
}

Node* merge(Node* &left , Node* &right){

    if(left == NULL) return right;
    if(right == NULL) return left;

    Node* answer = new Node(-1);
    Node* temp = answer;

    while(left != NULL && right != NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;

        }
    }
    while(left != NULL){
         temp->next = left;
            temp = left;
            left = left->next;
    }
    while(right != NULL){
        temp->next = right;
            temp = right;
            right = right->next;
    }

    answer = answer->next;
    return answer;
}

Node* mergeSort(Node* &head){
    if(head == NULL || head->next == NULL) return head;
    
    Node* mid = middle(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left,right);

}

int main()
{
    
    return 0;
}