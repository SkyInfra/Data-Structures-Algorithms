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
            cout << "node is added to list " << endl;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
        cout << "Node is added to list " << endl;
    }
    void insert_at_End(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "node is added to list " << endl;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        cout << "Node is added to list " << endl;
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
    list.insert_at_End(6);
    list.displayList();
    list.insert_at_End(7);
    list.displayList();
    return 0;
}