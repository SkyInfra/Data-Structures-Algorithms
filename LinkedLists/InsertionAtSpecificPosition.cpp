#include <iostream>
using namespace std;
struct Node
{
public:
    int value;
    Node *next;
    Node(int v)
    {
        this->value = v;
        this->next = NULL;
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
    void insert_value_at_start(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Node is added to list " << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "node is added to list " << endl;
    }
    void insert_at_specic_position(int v, int position)
    {
        Node *newNode = new Node(v);
        if (position <= 0)
        {
            cout << "Position is invalid " << endl;
            return;
        }
        if (position == 1)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                cout << "Node is added to list " << endl;
                return;
            }
            newNode->next = head;
            head = newNode;
            cout << "node is added to list " << endl;
            return;
        }
        int index = 1;
        Node *temp = head;
        while (temp->next != NULL && index < position - 1)
        {
            temp = temp->next;
            index++;
        }
        if (temp == NULL)
        {
            cout << "Position is not found " << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
        cout << "Node is added to list " << endl;
    }
    void displaylist()
    {
        if (head == NULL)
        {
            cout << "List is empty  " << endl;
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
    list.insert_value_at_start(5);
    list.insert_value_at_start(3);
    list.insert_value_at_start(2);
    list.insert_value_at_start(1);
    list.insert_at_specic_position(4,4);
    list.displaylist();
}