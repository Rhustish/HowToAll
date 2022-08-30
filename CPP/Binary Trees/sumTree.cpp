#include "binaryTree.cpp"

pair<bool,int> isSumTreeFast(Node* root){
    if(root == NULL) return {1,0};
    if(root->left == NULL && root->right == NULL) return {1,root->data};

    pair<bool,int> l = isSumTreeFast(root->left);
    pair<bool,int> r = isSumTreeFast(root->right);
    bool c = root->data == l.second + r.second;
    pair<bool,int> ans;
    ans.first = l.first && r.first && c;
    ans.second = l.second + r.second + root->data;
    return ans;
}

bool isSumTree(Node* root){
    
    return isSumTreeFast(root).first;

}

int main()
{
    
    return 0;
}