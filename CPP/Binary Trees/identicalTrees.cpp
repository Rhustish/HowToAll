#include<iostream>
#include "binaryTree.cpp"
using namespace std;

bool areIdentical(Node* root1 , Node* root2){
    if(root1 == NULL && root2 == NULL) return 1;
    bool check = 1;
    bool l = areIdentical(root1->left,root2->left);
    bool r = areIdentical(root1->right,root2->right);
    bool c = root1->data == root2->data;
    return l&&r&&c;
}

int main()
{
    
    return 0;
}