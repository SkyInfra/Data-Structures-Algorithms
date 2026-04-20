#include<iostream>
using namespace std;

class Queue {
    int size;
    string* arr;
    int front;
    int rear;

public:
    Queue(int v) {
        size = v;
        arr = new string[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || (rear + 1) % size == front);
    }

    // Insert at rear
    void pushRear(string a) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = a;
        cout << "Inserted at rear\n";
    }

    // Insert at front
    void pushFront(string v) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }

        arr[front] = v;
        cout << "Inserted at front\n";
    }

    // Delete from front
    void popFront() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted from front: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Delete from rear
    void popRear() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << "Deleted from rear: " << arr[rear] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
    }

    void displayTask() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "End\n";
    }
};

int main() {
    Queue q(5);

    q.pushRear("A");
    q.pushRear("B");
    q.pushFront("C");
    q.pushRear("D");

    q.displayTask();

    q.popFront();
    q.popRear();

    q.displayTask();

    return 0;
}
