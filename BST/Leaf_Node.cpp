
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};
class Tree{
    Node* root ;
    Tree(){
        root = NULL;
    }
    void min(Node* root){
        if(root == NULL){
            return ;
        }
        Node* temp =root;
        while(temp != NULL && temp->left != NULL){
            temp =temp->left;
        }
        cout << temp->value << endl;
    }
    void max(Node* root ){
        if(root == NULL){
            return ;
        }
        Node* temp = root;
        while(temp != NULL && temp->right != NULL){
            temp =temp->right ;
        }
        cout << "Max value is : " << temp->value << endl; 
    }
    void ascedingOrder(Node* root){
        if(root == NULL){
            return;
        }
        ascedingOrder(root->left);
        cout << root->value ;
        ascedingOrder(root->right);
    }
    Node* search(Node* root , int key){
        if(root == NULL){
            return;
        }
        if(root->value == key){
            return root;
        }
        if(key < root->value){
            search(root->left , key);
        }else{
            search(root->right, key);
        }
        return root;
    }
    void printLeaf(Node* root, int &count){

    if(root == NULL)
        return;

    // leaf node condition
    if(root->left == NULL && root->right == NULL){
        cout << root->value << " ";
        count++;
        return;
    }

    // traverse left and right subtree
    printLeaf(root->left, count);
    printLeaf(root->right, count);
}
};
