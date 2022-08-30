#include<iostream>
using namespace std;
   

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };




Node* kReverse(Node* head, int k) {
	//base case
    if(head == NULL) return NULL;
	
	//step 1 
	Node *prev,*next = NULL;
	Node *curr = head;
	int count = 0;
	while(count<k && curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	
	head->next = kReverse(next,k);
	return prev;
}