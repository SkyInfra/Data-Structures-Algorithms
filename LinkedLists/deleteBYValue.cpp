#include <iostream> 
using namespace std;
struct Node{
    public:
    int value ;
    Node* next ;
    Node(int v){
        this->value = v;
        this->next = NULL;
    }
};
class LinkedList{
    private :
        Node* head ;
        Node* tail;
    public:
    LinkedList(){
        head = tail = NULL;
    }
    void insert_value_at_start(int v){
        Node* newNode = new Node(v);
        if(head == NULL){
            head = tail =newNode;
            cout << "Node is added to list " << endl;
            return;
        }
        newNode -> next = head;
        head = newNode;
        cout << "node is added to list " << endl;
    }
    void delete_by_value(int v){
        if(head == NULL){
            cout << "list is empty" << endl;
            return;
        }
        Node* temp = head;
        if(head->value == v){
            head = head ->next ;
            if(head == NULL){
                tail = NULL;
            }
            temp->next = NULL;
            delete temp;
            cout << "Node is deleted from list " << endl;
        }
        while(temp -> next != NULL && temp ->next->value != v){
            temp = temp ->next;
        }
        if(temp->next == NULL){
            cout << "Value not  found " << endl;
            return;
        }
        Node* del = temp->next ;
        temp->next = del->next ;
        if(del == tail){
            tail = temp;
        }
        delete del;
        cout << "node is delete from list" << endl;
    }
    void displaylist(){
        if(head == NULL){
            cout << "List is empty  " << endl;
            return;
        }
        Node* temp = head ;
        while(temp != NULL){
            cout << temp->value << "<==> ";
            temp = temp -> next ; 
        }
        cout << "NULL" << endl;
    }
};
int main(){
    LinkedList list ;
    list.insert_value_at_start(5);
    list.insert_value_at_start(4);
    list.insert_value_at_start(3);
    list.insert_value_at_start(2);
    list.insert_value_at_start(1);
    list.displaylist();
    list.delete_by_value(1);
    list.displaylist();
    
}