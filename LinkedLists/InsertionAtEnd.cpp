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
    void insert_value_at_End(int v){
        Node* newNode = new Node(v);
        if(head == NULL){
            head = tail =newNode;
            cout << "Node is added to list " << endl;
            return;
        }
        tail-> next = newNode;
        tail = newNode;
        cout << "node is added to list " << endl;
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
    list.insert_value_at_End(1);
    list.insert_value_at_End(2);
    list.insert_value_at_End(3);
    list.insert_value_at_End(4); 
    list.insert_value_at_End(5);
    list.displaylist();
}