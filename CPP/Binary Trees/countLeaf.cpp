#include<iostream>
#include"binaryTree.cpp"
using namespace std;



int noOfLeafNodes(Node *root){
    if(root == NULL) return 0;
    

    
    cout<<"current node " << root -> data <<endl;
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

int main()
{
    
    return 0;
}