#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }


}

Node* insertIntoBST(Node* &root , int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }else if (data < root -> data){
        root-> left = insertIntoBST(root->left , data);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        insertIntoBST(root,data);
        cin>>data;
    }
}


int main()
{
    Node* n1 = NULL;    
    cout<<"Enter data to create bst"<<endl;

    takeInput(n1);
    cout<<"Printing NOW"<<endl;
    levelOrder(n1);
    return 0;
}