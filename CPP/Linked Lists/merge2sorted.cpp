#include<iostream>
#include"linkedlist.cpp"
using namespace std;


Node* merge(Node* &first , Node* &second){

    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        
        if(curr2->data >= curr1->data && curr2->data <= next1->data){

            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;

        }else{

            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL){

                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node* output(Node* first, Node* second){
    
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data <= second->data){
        return merge(first,second);
    }
    return merge(second,first);
}