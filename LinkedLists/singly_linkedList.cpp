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
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void add_at_start(int v)
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
        cout << "Node is added to list " << endl;
    }

    void add_at_specific_position(int v, int position)
    {
        Node *newNode = new Node(v);
        if (position <= 0)
        {
            cout << "Position is invalid " << endl;
            return;
        }
        if (position == 0)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                cout << "Node is added to the list " << endl;
                return;
            }
            newNode->next = head;
            head = newNode;
            cout << "Node is added to the list " << endl;
            return;
        }
        Node *temp = head;
        int index = 0;
        while (temp != NULL && index < position - 1)
        {
            index++;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position is not Found " << endl;
            delete newNode;
            return;
        }
        if (temp == tail)
        {
            tail->next = newNode;
            cout << "Node is added to list " << endl;
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
    void add_at_last(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Node is added to list " << endl;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        cout << "Node is added to last " << endl;
    }
    void printall()
    {
        if (head == NULL)
        {
            cout << "list is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " <==> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void add_position(int v, int position)
    {
        if (position < 0)
        {
            cout << "invalid position " << endl;
            return;
        }
        Node *newNode = new Node(v);
        if (position == 0)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                cout << "Node is added to list " << endl;
                return;
            }
        }
        Node *temp = head;
        int index = 0;
        while (temp != NULL && index < position - 1)
        {
            temp = temp->next;
            index++;
        }
        if (temp == NULL)
        {
            cout << "position is not found" << endl;
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
    void delete_first()
    {
        if (head == NULL)
        {
            cout << "list is empty " << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
        {
            tail = head;
        }
        cout << "Node is deleted from the list " << endl;
    }
    void delete_last()
    {
        if (head == NULL)
        {
            cout << "Node is empty " << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            cout << "Node is deleted from the list " << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
        cout << "Node is deleted from the last " << endl;
    }
    // void delete node by vlaue
    void delete_node_by_value(int v)
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        if (temp->value == v)
        {
            head = head->next;
            delete temp;
            if (head == NULL)
            {
                tail = NULL;
            }
            cout << "Node is deleted from list " << endl;
        }
        while (temp->next != NULL && temp->next->value != v)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Value is not found " << endl;
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        del->next = NULL;
        delete del;
        if (del == tail)
        {
            tail = temp;
        }
        cout << "Node is deleted from list " << endl;
        return;
    }
};

int main()
{
    LinkedList list;
    list.add_at_start(4);
    list.add_at_start(3);
    list.add_at_start(2);
    list.add_at_start(1);
    list.add_at_start(0);
    list.add_at_last(5);
    list.add_at_specific_position(6, 6);

    list.printall();
    list.delete_node_by_value(0); // list.delete_last();
    list.printall();
}