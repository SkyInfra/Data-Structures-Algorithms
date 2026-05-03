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
class Tree{
private:
    Node* root;

public:
    Tree(){
        root = NULL;
    }

    Node* add_Node_in_Tree(Node* root, int v){
        if(root == NULL){
            return new Node(v);
        }

        if(root->value > v){
            root->left = add_Node_in_Tree(root->left, v);
        }else{
            root->right = add_Node_in_Tree(root->right, v);
        }
        return root;
    }
       
    void Traverse_LevelOrder(Node* root){
        if(root == NULL) return;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp == NULL){
                cout << endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout << temp->value << " ";

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }

    void take_input(){
        int value;
        cout<<"Enter values (-1 to stop): ";
        cin >> value;

        while(value != -1){
            root = add_Node_in_Tree(root, value);
            cin >> value;
        }
    }

    void display(){
        Traverse_LevelOrder(root);
    }
};

int main(){
    Tree t;

    t.take_input();

    cout << endl;
    t.display();

    return 0;
}
