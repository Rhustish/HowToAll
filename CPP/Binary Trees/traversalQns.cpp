#include "binaryTree.cpp"




void lefts(vector<int> &ans , Node* root){
    if(root == NULL || (root->left == NULL  && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left == NULL){
        lefts(ans,root->right);
    }else{
        lefts(ans,root->left);
    }

}

void leafs(vector<int> &ans , Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    leafs(ans,root->left);
    leafs(ans,root->right);
    
}

void rights(vector<int> &ans , Node* root ){

    if(root == NULL || (root->left == NULL  && root->right == NULL)){
        return ;
    }

    if(root->right == NULL){
        rights(ans,root->left);
    }else{
        rights(ans,root->right);
    }
    ans.push_back(root->data);

}

vector<int> boundaryTraversal(Node* root){
    vector<int> ans;
    ans.push_back(root->data);
    //left exclusive leaf
    lefts(ans,root->left);

    //all leafs
    leafs(ans,root->left);
    leafs(ans,root->right);

    //all rights
    stack<int> s;
    rights(ans,root->right);
    for(int i = 0 ; i < s.size();i++){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

vector<int> zigZag(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;   
    queue<Node*> q;
    q.push(root);
    bool ltr =1;
    while(!q.empty()){
        //Level process
        int size = q.size();
        vector<int> a(size);
        for(int i = 0 ; i < size ; i++){
            Node* temp = q.front();
            q.pop();

            int idx = ltr ? i : size - i -1;
            a[idx] = temp->data;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }
        for( auto i : a){
            ans.push_back(i);
        }
        ltr = !ltr;
    }
    return ans;
}
