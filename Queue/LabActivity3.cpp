#include<iostream>
using namespace std;

class Queue{
    int size;
    int* arr;
    int front;
    int rear;

public:

    Queue(int s){
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear == size -1);
    }

    bool isEmpty(){
        return (front == -1);
    }

    void push_at_start(int c){

        if(front == 0){
            cout << "Queue Overflow" << endl;
            return;
        }

        if(isEmpty()){
            front = rear = 0;
        }
        else{
            front--;
        }

        arr[front] = c;
        cout << "Value added at front" << endl;
    }

    void push_AT_rear(int v){

        if(isFull()){
            cout << "Queue Overflow" << endl;
            return;
        }

        if(isEmpty()){
            front = rear = 0;
        }
        else{
            rear++;
        }

        arr[rear] = v;
        cout << "Value added at rear" << endl;
    }

    void pop_from_front(){

        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }

        cout << "Deleted from front" << endl;
    }

    void pop_from_rear(){

        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == rear){
            front = rear = -1;
        }
        else{
            rear--;
        }

        cout << "Deleted from rear" << endl;
    }
};

int main(){

    Queue q(5);

    q.push_AT_rear(10);
    q.push_AT_rear(20);
    q.push_at_start(5);

    q.pop_from_front();
    q.pop_from_rear();

}
