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

class Tree
{
    Node *root;

public:
    Tree()
    {
        root = NULL;
    }

    Node *add_Node(Node *root, int v)
    {
        if (root == NULL)
        {
            return new Node(v);
        }

        if (v < root->value)
        {
            root->left = add_Node(root->left, v);
        }
        else
        {
            root->right = add_Node(root->right, v);
        }

        return root;
    }
