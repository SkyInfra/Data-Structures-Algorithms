#include<iostream>
#include<queue>
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
