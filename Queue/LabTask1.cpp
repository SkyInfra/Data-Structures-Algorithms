#include<iostream>
using namespace std;
struct Node{
    int value ;
    Node* next ;
    Node(int v){
        this->value = v;
        this->next = NULL;
    }
};
class Queue{
    Node* front;
    Node* rear;
    public:
    Queue(){
        front = rear = NULL;
    }
    void push_at_rear(int v){
        Node* newNode = new Node(v);
        if(front == NULL){
            front = rear = newNode;
            cout << "Value is added to Queue " << endl;
            return;
        }
        rear ->next = newNode;
        rear = newNode;
        cout << "Value is added to Queue "<< endl;
    }
    void pop_from_front(){
        if(front == NULL){
            cout << "Queue underFlow  " << endl;
            return;
        }
        Node* temp = front;
        front = front ->next ;
        if(front == NULL){
            rear = NULL;
        }
        cout << "Deleteing value " << temp->value << endl;
        delete temp;   
    }
    void display(){
        if(front == NULL){
            cout << "Queue is empty " << endl;
            return;
        }
        Node* temp = front ;
        while(temp != NULL){
            cout << temp->value << " ";
            temp = temp->next ;
        }
    }
};
int main(){
    Queue list;

    list.push_at_rear(1);
    list.push_at_rear(2);
    list.push_at_rear(3);
    list.push_at_rear(4);
    list.push_at_rear(5);

    list.display();

    list.pop_from_front();

    list.display();


    return 0;
}
