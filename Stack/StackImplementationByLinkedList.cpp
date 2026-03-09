#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) {
        value = v;
        next = nullptr;
    }
};

class Stack {
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    void push(int v) {
        Node* newNode = new Node(v);
        if(head == NULL){
            head = newNode;
            cout << "Value added to stack" << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "Value added to stack" << endl;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Value deleted from stack" << endl;
    }

    int peek() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return head->value;
    }

    bool empty() {
        return head == nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); 

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}