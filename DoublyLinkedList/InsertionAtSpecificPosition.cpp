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
    void insert_At_Specific_Position(int v, int position)
    {
        Node *newNode = new Node(v);
        if (position <= 0)
        {
            cout << "Position is invalid  " << endl;
            delete newNode;
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
            head->prev = newNode;
            head = newNode;
            cout << "Node is added to list " << endl;
            return;
        }
        Node *temp = head;
        int index = 1;
        while (temp->next != NULL && index < position - 1)
        {
            temp = temp->next;
            index++;
        }
        if (temp->next == NULL)
        {
            cout << "position is not found " << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
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
    list.insert_At_Specific_Position(10,2);
    list.displayList();
    return 0;
}