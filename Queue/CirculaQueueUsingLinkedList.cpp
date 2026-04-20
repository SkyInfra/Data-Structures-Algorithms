#include<iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int v){
        value = v;
        next = NULL;
    }
};

class CircularQueue{
    Node* front;
    Node* rear;

public:
    CircularQueue(){
        front = rear = NULL;
    }

    void push(int v){
        Node* newNode = new Node(v);
        if(front == NULL){
            front = rear = newNode;
            rear->next = front; // circular link
            cout << "Value added to Queue: " << v << endl;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
        cout << "Value added to Queue: " << v << endl;
    }

    void pop(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Deleting value: " << temp->value << endl;

        if(front == rear){  // only one node
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;  // maintain circular link
        }

        delete temp;
    }

    void displayInfo(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do{
            cout << temp->value << " ";
            temp = temp->next;
        }while(temp != front);
        cout << endl;
    }
};

int main(){
    CircularQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.displayInfo();

    q.pop();
    q.displayInfo();

    q.push(40);
    q.push(50);
    q.displayInfo();

    return 0;
}