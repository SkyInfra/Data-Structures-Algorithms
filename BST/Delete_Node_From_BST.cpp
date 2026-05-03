
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
