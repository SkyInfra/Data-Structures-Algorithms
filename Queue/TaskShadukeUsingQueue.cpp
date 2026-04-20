#include<iostream>
using namespace std;
class Queue{
    int size ;
    string* arr;
    int front;
    int rear;
    
    public:

    Queue(int v){
        this->size = v;
        this->arr = new string[size];
        this->front = -1;
        this->rear = -1;
    }

    bool isEmpty(){
        return (front == -1);
    }
    bool isFull(){
        return(rear = size - 1);
    }

    void pushRear(string a){
        if(isFull()){
            cout << "Queue overFlow " << endl;
            return;

        }
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear++;
        }
        arr[rear] = a;
        cout << "Task Added to Queue " << endl;
    }

    void pushFront(string v){
        if(isFull()){
            cout << "Queue overFlow " << endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        }
        else{
            front--;
        }
        arr[front] = v;
        cout << "Task is added to Queue "<< endl;
    }
    void popFront(){
        if(isEmpty()){
            cout << "Queue UnderFlow " << endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        }else{
            front++;
        }
        cout << "Task  is deleted from Queue " << endl;
    }

    void popRear(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
        }else{
            rear--;
        }
        cout << "Deleting the Task " << endl;
    }
    void displayTask(){
        if(isEmpty())[
            cout << "Queue UnderFLow " << endl;
            return;
        ]
        for(int i = front  i<= rear ; i++){
            cout << arr[i] << " " ;
        }   
        cout << "End " << endl;
    }
}
int main(){
    return 0;
}
