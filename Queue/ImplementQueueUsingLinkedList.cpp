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

class LinkedList{

    Node* qfront;
    Node* rear;

public:

    LinkedList(){
        qfront = rear = NULL;
    }

    void push(int v){

        Node* newNode = new Node(v);

        if(qfront == NULL){
            qfront = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Value added to Queue" << endl;
    }

    void pop(){

        if(qfront == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = qfront;

        cout << "Deleted: " << temp->value << endl;

        qfront = qfront->next;

        delete temp;

        if(qfront == NULL){
            rear = NULL;
        }
    }

    void displayInfo(){

        if(qfront == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = qfront;

        while(temp != NULL){
            cout << temp->value << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    bool isempty(){
        return (qfront == NULL);
    }
};

int main(){

    LinkedList list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);

    list.displayInfo();

    list.pop();

    list.displayInfo();

    cout << "Is Queue empty: " << list.isempty() << endl;

    return 0;
}
