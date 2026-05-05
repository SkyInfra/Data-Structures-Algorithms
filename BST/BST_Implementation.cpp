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
 void Max_Value(Node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }

        Node *temp = root;

        while (temp->right != NULL)
        {
            temp = temp->right;
        }

        cout << "Max Value: " << temp->value << endl;
    }

    void Min_Value(Node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }

        Node *temp = root;

        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        cout << "Min Value: " << temp->value << endl;
    }
    void add_Node(int v){

    Node* newNode = new Node(v);

    if(root == NULL){
        root = newNode;
        return;
    }

    Node* temp = root;

    while(true){

        if(v < temp->value){

            if(temp->left == NULL){
                temp->left = newNode;
                break;
            }
            else{
                temp = temp->left;
            }

        }
        else{

            if(temp->right == NULL){
                temp->right = newNode;
                break;
            }
            else{
                temp = temp->right;
            }

        }

    }

    cout << "Value added to tree" << endl;
}
    void display()
    {
        cout << "Inorder: ";
        inOrder(root);
        cout << endl;

        cout << "Preorder: ";
        preOrder(root);
        cout << endl;

        cout << "Postorder: ";
        postOrder(root);
        cout << endl;
    }
};

int main()
{

    Tree t;

    t.insert(10);
    t.insert(5);
    t.insert(20);
    t.insert(3);
    t.insert(7);

    t.display();

    

    return 0;
}
