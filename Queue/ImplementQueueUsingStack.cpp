#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    Queue() {
    }

    void push(int v) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            int value = s1.top();
            s1.pop();
            s2.push(value);
        }

        // Push new element into s1
        s1.push(v);

        // Move everything back to s1
        while (!s2.empty()) {
            int value = s2.top();
            s2.pop();
            s1.push(value);
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int top() {
        if (s1.empty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s1.top();
    }

    bool isempty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.top() << endl;

    cout << "Removed: " << q.pop() << endl;
    cout << "Front after pop: " << q.top() << endl;

    return 0;
}
