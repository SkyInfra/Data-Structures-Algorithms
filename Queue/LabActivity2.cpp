#include<iostream>
using namespace std;
class Queue{
    int size ;
    int* arr;
    int front ;
    int rear ;
    public:
    Queue(int v){

        this->size = v;
        this->arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (front == (rear + 1) % size );
    }

    void push(int s){
        if(isFull()){
            cout << "Queue overFlow " << endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear+1) % size ;
        }
        arr[rear] = s;
        cout << "Value is added to Queue " << endl;
    }
    void pop(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return;
        }
        if(front == rear){
            front  = rear = -1;
        }else{
            front = (front + 1) % size ;
        }
        cout << "Value is deleted from queue " << endl;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return;
        }
        int i = front;
        while(true){
            cout << arr[i] << " ";
            if(i == rear){
                break;
            }
            i = (i + 1) % size;
        }
        cout << "endl" ;
    }

};
int main(){
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    q.pop();

    q.display();

    q.pop();

    q.display();
    q.pop();

    q.display();

}
