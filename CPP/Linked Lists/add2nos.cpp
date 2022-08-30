#include<iostream>
#include "linkedlist.cpp"
using namespace std;

Node* add(Node* &head1 , Node* &head2){

    Node* h1r = reverse(head1);
    Node* h2r = reverse(head2);
    Node* answer = NULL;
    Node* answertail = answer;
    int carry = 0;
    while(h1r != NULL && h2r != NULL){
        int currsum = h1r->data + h2r->data + carry;
        int currdig = currsum%10;
        insertattail2(answer,answertail,currdig);
        carry = currsum/10;
        h1r = h1r->next; h2r = h2r->next;
    }

    while(h2r != NULL){
        int currsum = carry + h2r->data;
        int currdig = currsum%10;
        insertattail2(answer,answertail,currdig);
        carry = currsum/10;
        h2r = h2r->next;
    }

    while(h1r != NULL){
        int currsum = carry + h1r->data;
        int currdig = currsum % 10;
        insertattail2(answer,answertail,currdig);
        carry = currsum/10;
        h1r = h1r->next;
    }

    while(carry > 0){
        insertattail2(answer,answertail,carry%10);
        carry/=10;
    }

    return reverse(answer->next);
}






int main()
{
    int n = 23412354;
    int k = 52345623;
    Node* number1 = itoll(n);
    Node* number2 = itoll(k);
    print(add(number1,number2));
    
    return 0;
}