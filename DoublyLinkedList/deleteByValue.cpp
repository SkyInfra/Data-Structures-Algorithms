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
    void insert_At_Start(int v){
        Node* newNode = new Node(v);
        if(head == NULL){
            head = tail = newNode;
            cout << "Node  is added to list " << endl;
            return;
        }
        newNode->next = head ;
        head ->prev = newNode;
        head = newNode;
        cout << "node is added to list " << endl;
    }
    void deleted_by_value(int v){
        if(head == NULL){
            cout << "list is empty "<< endl;
            return;
        }
        Node* temp = head ;
        if(head->value == v){
            head = head -> next ;
            head->prev = NULL;
            if(head->next == NULL){
                tail = NULL;
            }

            delete temp ;
            cout << "Node is deleted from list " << endl;
            return;
        }
        while(temp ->next != NULL && temp->next->value != v){
            temp =temp->next ;
        }
        if(temp->next == NULL){
            cout << "Value is not found " << endl;
            return;
        }
        Node* del = temp->next ;
        if(del->next == NULL){
            tail = NULL;
            delete del;
            cout << "Node is deleted " << endl;
            return;
        }
        temp->next = del->next;
        del->next->prev = temp;
        delete del;
        cout << "Node is deleted from the list " << endl;
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
    list.insert_At_Start(5);
    list.insert_At_Start(4);
    list.insert_At_Start(3);
    list.insert_At_Start(2);
    list.insert_At_Start(1);
    list.displayList();
    list.deleted_by_value(5);
    list.displayList(); 
    return 0;
}