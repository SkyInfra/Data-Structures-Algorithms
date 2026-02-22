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
            tail->next = head;
            cout << "node is added to list " << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
        cout << "Node is added to list " << endl;
    }
    void insert_before_specific_position(int v, int position)
    {
        Node *newNode = new Node(v);
        if (position <= 0)
        {
            cout << "invalid position " << endl;
            delete newNode;
            return;
        }
        if (position == 1 || position == 2)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                tail->next = head;
                cout << "Node is added to list " << endl;
                return;
            }
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
            cout << "node is added to list " << endl;
            return;
        }
        Node *temp = head;
        int index = 1;
        while (temp->next != head && index <= (position - 2))
        {
            temp = temp->next;
            index++;
        }
        if (index != (position - 2))
        {
            delete newNode;
            cout << "Position is not found " << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == head)
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
    list.insert_before_specific_position(10, 2);
    list.displayList();
    return 0;
}