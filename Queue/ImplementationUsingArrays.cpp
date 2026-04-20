#include<iostream>
using namespace std;

class Queue{

    int qfront;
    int rear;
    int* arr;
    int size;

public:

    Queue(int s){
        size = s;
        arr = new int[size];
        qfront = 0;
        rear = -1;
    }

    void push(int value){
        if(rear < size-1){
            rear++;
            arr[rear] = value;
            cout << "Value added to Queue" << endl;
        }
        else{
            cout << "Queue Overflow" << endl;
        }
    }

    void pop(){
        if(qfront > rear){
            cout << "Queue is empty" << endl;
        }
        else{
            qfront++;
            cout << "Value deleted from queue" << endl;
        }
    }

    bool isEmpty(){
        if(qfront > rear){
            return true;
        }
        return false;
    }

    bool isFull(){
        if( qfront == 0 && rear == size-1){
            return true;
        }
        return false;
    }

    void display(){
        if(qfront > rear){
            cout << "Queue is empty " << endl;
            return;
         }

        cout << "Queue elements: ";
        for(int i = qfront ; i <= rear ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.display();

    q.pop();

    return 0;
}
