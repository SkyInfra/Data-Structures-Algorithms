#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int task_id;
    string task_name;
    string task_des;
    string priority;
    int date;
    Node *next;
    Node(int task_id, string task_name, string task_des, string priority, int date)
    {
        this->task_id = task_id;
        this->task_name = task_name;
        this->task_des = task_des;
        this->priority = priority;
        this->date = date;
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
    void add_Task_at_start(int task_id, string task_name, string task_des, string priority, int date)
    {
        Node *newNode = new Node(task_id, task_name, task_des, priority, date);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Task Added to the list " << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "Task is to the list " << endl;
    }
    // void add task at the end ;
    void add_task_at_End(int task_id, string task_name, string task_des, string priority, int date)
    {
        Node *newNode = new Node(task_id, task_name, task_des, priority, date);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Task is added to the list" << endl;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        cout << "Task is added to list " << endl;
    }
    // dispay in reverse order
    void display_in_reverse_order()
    {
        if (head == NULL)
        {
            cout << "list is empty " << endl;
            return;
        }
        vector<Node> list;
        Node *temp = head;
        while (temp != NULL)
        {
            Node task(temp->task_id, temp->task_name, temp->task_des, temp->priority, temp->date);
            list.push_back(task);
            temp = temp->next;
        }

        // display in revers order
        for (int i = list.size() - 1; i >= 0; i--)
        {
            cout << "Task ID      : " << list[i].task_id << endl;
            cout << "Task Name    : " << list[i].task_name << endl;
            cout << "Description  : " << list[i].task_des << endl;
            cout << "Priority     : " << list[i].priority << endl;
            cout << "Due Date     : " << list[i].date << endl;
            cout << "---------------------------" << endl;
        }
    }
    // Search
    void search_task_by_ID(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->task_id == id)
            {
                cout << "Task ID      : " << temp->task_id << endl;
                cout << "Task Name    : " << temp->task_name << endl;
                cout << "Description  : " << temp->task_des << endl;
                cout << "Priority     : " << temp->priority << endl;
                cout << "Due Date     : " << temp->date << endl;
                cout << "---------------------------" << endl;
            }
            temp = temp->next;
        }
    }
    // insert at specific index
    void insert_at_specific_index(int task_id, string task_name, string task_des, string priority, int date, int position)
    {

        Node *newNode = new Node(task_id, task_name, task_des, priority, date);
        if (position == 1)
        {
            newNode -> next = head ;
            head = newNode;
            cout << "Task is added to the list " << endl;
            return;
        }
        Node *temp = head;
        int index = 1;
        while (temp != NULL && index < position-1)
        {
            index++;
            temp = temp->next;
        }
        if(temp == NULL){
            cout << "Invalid position " << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if(newNode->next == NULL){
            tail = newNode;
        }
        cout << "Task is added to the list " << endl;
    }
    void delete_task_by_id(int id)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->task_id == id)
        {
            head = head->next;
            if(head == NULL){
                tail = NULL;
            }
            delete temp;
            cout << "Task is deleted from the list " << endl;
            return;
        }
        while (temp->next != NULL && temp->next->task_id != id)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Task not found " << endl;
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Task is deleted from the list " << endl;
    }
};
int main()
{
    LinkedList taskList;
    int choice;

    do
    {
        cout << "\n";
        cout << "=====================================\n";
        cout << "        TASK MANAGEMENT SYSTEM       \n";
        cout << "=====================================\n";
        cout << "1. Add Task at Start\n";
        cout << "2. Add Task at End\n";
        cout << "3. Insert Task at Position\n";
        cout << "4. Delete Task by ID\n";
        cout << "5. Search Task by ID\n";
        cout << "6. Display Tasks (Reverse Order)\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int id, date, position;
        string name, desc, priority;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Task ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Task Name: ";
            getline(cin, name);
            cout << "Enter Description: ";
            getline(cin, desc);
            cout << "Enter Priority: ";
            getline(cin, priority);
            cout << "Enter Due Date: ";
            cin >> date;

            taskList.add_Task_at_start(id, name, desc, priority, date);
            break;

        case 2:
            cout << "\nEnter Task ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Task Name: ";
            getline(cin, name);
            cout << "Enter Description: ";
            getline(cin, desc);
            cout << "Enter Priority: ";
            getline(cin, priority);
            cout << "Enter Due Date: ";
            cin >> date;

            taskList.add_task_at_End(id, name, desc, priority, date);
            break;

        case 3:
            cout << "\nEnter Position: ";
            cin >> position;
            cout << "Enter Task ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Task Name: ";
            getline(cin, name);
            cout << "Enter Description: ";
            getline(cin, desc);
            cout << "Enter Priority: ";
            getline(cin, priority);
            cout << "Enter Due Date: ";
            cin >> date;

            taskList.insert_at_specific_index(id, name, desc, priority, date, position);
            break;

        case 4:
            cout << "\nEnter Task ID to delete: ";
            cin >> id;
            taskList.delete_task_by_id(id);
            break;

        case 5:
            cout << "\nEnter Task ID to search: ";
            cin >> id;
            taskList.search_task_by_ID(id);
            break;

        case 6:
            taskList.display_in_reverse_order();
            break;

        case 0:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}