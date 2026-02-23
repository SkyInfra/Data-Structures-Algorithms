#include <iostream>
using namespace std;
struct Node {
    public:
    int value ;
    Node* next ;
    Node* prev ;
    Node(int v){
        this->value = v;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList{
    private :
        Node * head ;
        Node* tail;
    public:
    LinkedList(){
        head = tail = NULL;
    }
    void insert_At_End(int v){
        Node* newNode = new Node(v);
        if(head == NULL){
            head = tail = newNode;
            cout << "Node  is added to list " << endl;
            return;
        }
        tail->next = newNode;
        newNode ->prev = tail;
        tail= newNode;
        cout << "node is added to list  " << endl;
    }
    void displayList(){
        if(head == NULL){
            cout << "List is empty " << endl;
            return;
        }
        Node* temp = head ;
        while(temp != NULL){
            cout << temp->value << "<==> ";
            temp = temp ->next ;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    LinkedList list ;
    list.insert_At_End(5);
    list.insert_At_End(4);
    list.insert_At_End(3);
    list.insert_At_End(2);
    list.insert_At_End(1);
    list.displayList();
    return 0;
}