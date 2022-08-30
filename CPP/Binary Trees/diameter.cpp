#include"binaryTree.cpp"
#include<iostream>
using namespace std;

pair<int,int> diameterFast(Node* root){
    if(root == NULL) return {0,0};
    pair<int,int> l = diameterFast(root->left);
    pair<int,int> r = diameterFast(root->right);

    int op1 = l.first;
    int op2 = r.first;
    int op3 = l.second + r.second + 1;
    pair<int,int> ans = {
        (max(op1,(max(op2,op3)))),
        max(l.second,r.second) + 1
    };
    return ans;
}


//O(n^2)
int diameter(Node* root){

    int dl = diameter(root->left);
    int dr = diameter(root->right);
    int dc = 1 + height(root->left) + height(root->right) ;

    return max(dl,(max(dr,dc)));
}

int main()
{
    
    return 0;
}