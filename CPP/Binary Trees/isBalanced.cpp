#include<iostream>
#include "binaryTree.cpp"
using namespace std;

pair<bool,int> isBalancedFast(Node* root){
        
    if(root == NULL) return {1,0};
    
    pair<bool,int> l = isBalancedFast(root->left);
    pair<bool,int> r = isBalancedFast(root->right);
    
    bool lefta = l.first;
    bool righta = r.first;
    
    bool diff = abs(r.second - l.second) <= 1;
    
    pair<bool,int> ans;
    ans.second = max(l.second , r.second) + 1;
    
    if(lefta && righta && diff){
        ans.first = 1;
    }else{
        ans.first = false;
    }
    return ans;
 
}
bool isBalanced(Node *root){
    if(root == NULL) return 1;

    bool l = isBalanced(root->left);
    bool r = isBalanced(root->right);
    int heightdiff = max(height(root->left),height(root->right)) - min(height(root->left),height(root->right));
    bool c = heightdiff <=1 ? 1 :0;
    if(l && r && c) return 1;
    return 0;
}

int main()
{
    
    return 0;
}