#include<iostream>
#include"linkedlist.cpp"
using namespace std;

void halfLists(Node* &head){
    

    //using slow-fast approach to find the positions of the end of new arrays
    Node* fast = head;
    Node* slow = head;
    while(fast -> next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next != head){
        fast = fast->next;\
    }

    Node* head2 = slow->next;
    fast->next = head2;
    slow->next = head;

    printCircular(head);
    printCircular(head2);

}
int main()
{
    
    return 0;
}