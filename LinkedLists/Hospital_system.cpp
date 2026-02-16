#include <iostream>
using namespace std;
struct Node
{
    int reg_id;
    string name;
    string address;
    int age;
    int phone;
    Node *next;
    Node(int reg_id, string name, string address, int age, int phone)
    {
        this->reg_id = reg_id;
        this->name = name;
        this->address = address;
        this->age = age;
        this->phone = phone;
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
    void add_patient_at_start(int reg_id, string name, string address, int age, int phone)
    {
        Node *newNode = new Node(reg_id, name, address, age, phone);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Patient added at the start of list " << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "Patient is added at the start of list " << endl;
    }
    void add_patient_at_the_end(int reg_id, string name, string address, int age, int phone)
    {
        Node *newNode = new Node(reg_id, name, address, age, phone);
        if (head == NULL)
        {
            head = tail = newNode;
            cout << "Patient is added at the end of the list " << endl;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        cout << "Patient is added at the end of the list " << endl;
    }
    void add_patient_at_specific_Index(int reg_id, string name, string address, int age, int phone, int position)
    {
        Node *newNode = new Node(reg_id, name, address, age, phone);
        if (position == 1)
        {
            if (head == NULL)
            {
                head = tail = newNode;
                cout << "Patient is added to list at specifc index " << endl;
                return;
            }
            newNode->next = head;
            head = newNode;
            cout << "Patient is added to list " << endl;
        }
        int index = 0;
        Node *temp = head;
        while (temp != NULL && index < position - 1)
        {
            index++;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position is not foud " << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
        cout << "Patient is added to the list at specific index " << endl;
    }
    void delete_patient_by_id(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        if (head->reg_id == id)
        {
            head = head->next;
            if (head == NULL)
            {
                tail = NULL;
            }
            delete temp;
            cout << "Patient is deleted from the list " << endl;
        }
        while (temp->next != NULL && temp->next->reg_id != id)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Patient not found\n";
            return;
        }
        Node *del = temp->next;
        temp->next = del->next;
        if (del == tail)
        {
            tail = temp;
        }
        delete del;
        cout << "Patient is deleted from the list" << endl;
    }
    void print_All_Patient()
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "----------------------" << endl;
            cout << "Name    : " << temp->name << endl;
            cout << "Adress  : " << temp->address << endl;
            cout << "Reg_id  : " << temp->reg_id << endl;
            cout << "Age     : " << temp->age << endl;
            cout << "Phone   : " << temp->phone << endl;
            cout << "----------------------" << endl;
            temp = temp->next;
        }
    }
    void search_patient_BY_id(int id)
    {
        if (head == NULL)
        {
            cout << "List is empty " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->reg_id == id)
            {
                cout << "----------------------" << endl;
                cout << "Name    : " << temp->name << endl;
                cout << "Adress  : " << temp->address << endl;
                cout << "Reg_id  : " << temp->reg_id << endl;
                cout << "Age     : " << temp->age << endl;
                cout << "Phone   : " << temp->phone << endl;
                cout << "----------------------" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Patient is not found " << endl;
    }
};
int main()
{
    LinkedList hospital;
    int choice;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "     HOSPITAL PATIENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Patient at Start\n";
        cout << "2. Add Patient at End\n";
        cout << "3. Add Patient at Position\n";
        cout << "4. Delete Patient by ID\n";
        cout << "5. Search Patient by ID\n";
        cout << "6. Display All Patients\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting program...\n";
            break;
        }

        int id, age, phone, position;
        string name, address;

        if (choice == 1)
        {
            cout << "Enter Reg ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Phone: ";
            cin >> phone;

            hospital.add_patient_at_start(id, name, address, age, phone);
        }
        else if (choice == 2)
        {
            cout << "Enter Reg ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Phone: ";
            cin >> phone;

            hospital.add_patient_at_the_end(id, name, address, age, phone);
        }
        else if (choice == 3)
        {
            cout << "Enter Position: ";
            cin >> position;
            cout << "Enter Reg ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Address: ";
            getline(cin, address);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Phone: ";
            cin >> phone;

            hospital.add_patient_at_specific_Index(id, name, address, age, phone, position);
        }
        else if (choice == 4)
        {
            cout << "Enter Reg ID to delete: ";
            cin >> id;
            hospital.delete_patient_by_id(id);
        }
        else if (choice == 5)
        {
            cout << "Enter Reg ID to search: ";
            cin >> id;
            hospital.search_patient_BY_id(id);
        }
        else if (choice == 6)
        {
            hospital.print_All_Patient();
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}