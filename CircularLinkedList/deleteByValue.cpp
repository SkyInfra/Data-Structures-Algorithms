#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
    Node(int v)
    {
        this->value = v;
        this->next = NULL;
    }
};
class Linkedlist
{
private:
    Node *head;
    Node *tail;

public:
    Linkedlist()
    {
        head = tail = NULL;
    }
    void add_at_start(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = tail = newNode;
            tail-> next = head ;
            cout << "node is added to list " << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
        cout << "Node is added to list " << endl;
    }
    void delete_By_Value(int v){
        if(head == NULL){
            cout << "List is empty "<< endl;
            return;
        }
        Node* temp = head;
        if(head->value == v){
            head = head -> next ;
             delete temp ;
            tail-> next = head ;
            cout << "Node is deleted from list " << endl;
            return;
        }
        while(temp->next != head &&temp->next->value != v){
            temp = temp ->next;
        }
        if(temp->next == head){
            cout << "value is not found "<< endl;
            return;
        }
        Node* del= temp->next ;
        temp->next = del-> next ;
        if(del-> next == head){
            tail = temp;
        }
        delete del;
        cout << "node is deleted from list" << endl;

    }
    void displayList()
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (true)
        {
            cout << temp->value << "<==> ";
            temp = temp->next;
            if (temp == head)
            {
                break;
            }
        }
        cout << "back to head again " << endl;
    }

};
int main()
{
    Linkedlist list;
    list.add_at_start(5);
    list.add_at_start(4);
    list.add_at_start(3);
    list.add_at_start(2);
    list.add_at_start(1);
    list.displayList();
    list.delete_By_Value(3);
    list.displayList();
    return 0;
}