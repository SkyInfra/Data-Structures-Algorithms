
#include<iostream>
using namespace std;
#include <iostream>
#include<queue>
using namespace std;
struct Node {
    int value ;
    Node* left ;
    Node* right;

    Node(int v){
        this->value =v;
        this->left = NULL;
        this-right = NULL;
    }
};
class Tree{
    Node* root;
    Tree(){
        root = nullptr;
    }
    Node* finMind(Node* root , int key){
        while(root != NULL && root->left != NULL){
            root = root->left ;
        }
        return root ;
    }
    Node* delete_Node(Node* root , int key){
        if(root == NULL){
            return ;
        }
        if(key < root->value){
            root->left = delete_Node(root->left , key);
        }else{
            root->right = delete_Node(root->right, key);
        }else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return;
            }else if(root->left == NULL){
                Node* temp = root->right ;
                delete temp;
                return;
            }else if(temp->right == NULL){
                Node* temp = root->left ;
                delete temp;
                return;
            }
            Node* temp = finMind(root->right);
            root->value = temp->value ;
            root->right = delete_Node(root->right);
        }
        return root;
    }
};
int main(){
    return 0;
}
