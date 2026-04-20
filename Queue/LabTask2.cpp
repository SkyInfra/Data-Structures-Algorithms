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

class Queue{

    Node* front;
    Node* rear;

public:

    Queue(){
        front = rear = NULL;
    }

    void push_AT_front(int v){

        Node* newNode = new Node(v);

        if(front == NULL){
            front = rear = newNode;
        }
        else{
            newNode->next = front;
            front = newNode;
        }

        cout << "Value added at front" << endl;
    }

    void push_at_rear(int v){

        Node* newNode = new Node(v);

        if(front == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Value added at rear" << endl;
    }

    void pop_from_front(){

        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        front = front->next;

        cout << "Deleting value: " << temp->value << endl;

        delete temp;

        if(front == NULL)
            rear = NULL;
    }

    void pop_from_rear(){

        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == rear){
            cout << "Deleting value: " << rear->value << endl;
            delete rear;
            front = rear = NULL;
            return;
        }

        Node* temp = front;

        while(temp->next != rear){
            temp = temp->next;
        }

        cout << "Deleting value: " << rear->value << endl;

        delete rear;

        rear = temp;
        rear->next = NULL;
    }
};

int main(){

    Queue q;

    q.push_AT_front(10);
    q.push_at_rear(20);
    q.push_AT_front(5);

    q.pop_from_front();
    q.pop_from_rear();

}
