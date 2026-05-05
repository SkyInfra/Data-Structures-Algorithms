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
         void preOrder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->value << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(Node *root)
    {
        if (root == NULL)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->value << " ";
    }
    Node *search(Node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }

        Node *temp = root;

        while (temp != NULL)
        {
            if (temp->value == key)
            {
                return temp;
            }
            else if (key < temp->value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        return NULL;
    }
    Node *search_list(Node *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->value == key)
        {
            return root;
        }

        if (key < root->value)
        {
            return search_list(root->left, key);
        }
        else
        {
            return search_list(root->right, key);
        }
    }
        return root;
    }
