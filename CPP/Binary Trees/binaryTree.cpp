#include<iostream>
#include<queue>
#include<limits>
#include<vector>
#include<stack>
#include<map>
using namespace std;

class Node{

    public:

    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    } 
};

Node* buildTree(Node* root){
    cout<<"Enter the data : "<<endl;
    int data; cin>>data;
    root = new Node(data);

    if(data == -1) return NULL;
    
    cout<<"Enter left node of data "<<data<<" : "<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter right node of data "<<data<<" : "<<endl;
    root->right = buildTree(root->right);
           
    return root;
}



void inOrder(Node* root){
    if(root == NULL)return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL)return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL)return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void levelOrder(Node* root){
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
            cout<<temp->data<< " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void levelPrint(Node* root , int level){
    if(root == NULL) return;
    else if(level == 1) cout<<root->data<<endl;
    else if( level > 1){
        levelPrint(root->left,level-1);
        levelPrint(root->right,level-1);
    };
}

int height(Node* root){
    if(root == NULL) return 0;
    int hl = height(root->left);
    int hr = height(root->right);  
    int height = max(hl,hr) + 1;

    return height;
}

int size(Node* root){
    if(root == NULL) return 0;

    int ls = size(root->left);
    int rs = size(root->right);

    return ls+rs+1;

}

int maxInBT(Node* root){

    if(root == NULL) return INT32_MIN;

    int lm = maxInBT(root->left);
    int rm = maxInBT(root->right);

    return max(root->data,max(lm,rm));

}

 


