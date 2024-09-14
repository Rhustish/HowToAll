#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char val;
    vector<Node*> children;
    bool isTerminal;

    Node( char c ) : val(c) , children(26,nullptr) , isTerminal(false) {}
};

class Trie{

    Node* root;

    void insertWordRecursion(Node* node , string word){
        if(!word.length()){
            node->isTerminal = 1;
            return;
        }
        if( node->children[word[0]-'a'] != nullptr ){
            insertWordRecursion(node->children[word[0]-'a'] , word.substr(1));
        }else{
            Node* child  = new Node(word[0]);
            node->children[word[0]-'a'] = child;
            insertWordRecursion(node->children[word[0]-'a'] , word.substr(1) );
        }
    }

    bool searchWordRecursion(Node* node , string word){
        if(word == ""){
            return node->isTerminal ;
        }
        if( node->children[word[0] - 'a'] == nullptr ) return 0;
        
        return searchWordRecursion(node->children[word[0] - 'a'] , word.substr(1)); 
    }

    Node* deleteWordRecursion(Node* node , string word){
        if(word == ""){
            return node->isTerminal ? node : nullptr ;
        }
        if( node->children[word[0] - 'a'] == nullptr ) return nullptr;
        
        return deleteWordRecursion(node->children[word[0] - 'a'] , word.substr(1)); 
    }


    public:

    Trie(){
        root = new Node('\0');
    }

    void insert( string word){
        insertWordRecursion(root,word);
    }

    bool search( string word){
        return searchWordRecursion(root , word);
    }

    void remove( string word ){
        Node* node =  deleteWordRecursion( root , word );
        if(node == nullptr) return;
        node->isTerminal = false;
    }

};

int main(){
    Trie t;
    t.insert("hello");
    cout<<t.search("hell");
}

