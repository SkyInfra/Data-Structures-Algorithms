#include <iostream>
using namespace std;
struct Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int v)
    {
        this->value = v;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    void insert_At_Start(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Node  is added to list " << endl;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        cout << "node is added to list " << endl;
    }
    void delete_from_start()
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            cout << "Node is deleted from the list " << endl;
            return;
        }
        head = head->next;
        delete temp;
        if (head->next == NULL)
        {
            tail = NULL;
        }
        cout << "Node is deleted from the list " << endl;
    }
    void displayList()
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "<==> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    LinkedList list;
    list.insert_At_Start(5);
    list.insert_At_Start(4);
    list.insert_At_Start(3);
    list.insert_At_Start(2);
    list.insert_At_Start(1);
    list.displayList();
    list.delete_from_start();
    list.displayList();
    list.delete_from_start();
    list.displayList();
    list.delete_from_start();
    list.displayList();
    list.delete_from_start();
    list.displayList();
    list.delete_from_start();
    list.displayList();
    return 0;
   
}