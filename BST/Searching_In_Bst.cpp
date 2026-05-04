#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};
class Tree{
private:
    Node* root;

public:
    Tree(){
        // Manually creating a BST
        root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(15);
        root->left->left = new Node(3);
        root->left->right = new Node(7);
    }

    // Recursive Search
    bool search_recursive(Node* root, int v){
        if(root == NULL){
            return false;
        }

        if(root->value == v){
            return true;
        }
        else if(v < root->value){
            return search_recursive(root->left, v);
        }
        else{
            return search_recursive(root->right, v);
        }
    }
