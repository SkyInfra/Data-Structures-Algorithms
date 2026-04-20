#include <iostream>
using namespace std;
class CircularQueue{
    int* arr ; 
    int size ;
    int front ;
    int rear ;
    CircularQueue(int x){
        this->size = x;
        this->rear = -1;
        this->front = -1;
        this->arr = new int[size];
    }
    bool isEmpty(){
        return (front == -1) ;
    }
    bool isFull(){
        return ((rear + 1) % size  == front );
    }
    void push(int v){
        if(isFull()){
            cout << "Queue is full " << endl;
            return;
        }
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear +1 ) % size ;
        }
        arr[rear] =  v;
        cout << "Value is added to Queue" << endl;
    }

    void pop(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return;
        }
        cout << "Deleting value is  : " << arr[front] << endl;
        if(front == rear ){
            front = rear = -1;
        }else{
        front = (front + 1) % size;
        }
    }
    void displayQueue(){
        if(isEmpty()){
            cout << "Queue is empty " << endl;
            return;
        }
        for(int i = front ;  i <=  rear ; i++){
            cout << arr[i] << endl;
        }
    }
    
}
int main(){
    return 0;
}
