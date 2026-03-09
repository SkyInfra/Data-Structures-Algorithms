#include<iostream>
using namespace std;
class Stack{
    int size ;
    int top; 
    int* arr;
    public :
    Stack(int s){
        this->size = s;
        this->top = -1;
        this->arr = new int[size];
    }
    void push(int v){
        if(top < size - 1){
            top++;
            arr[top] = v;
            cout << "Value is added to stack" << endl;
        }else{
            cout << "Stack oveFlow " << endl;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Stack underFlow " << endl;
            return;
        }else{
            top--;
            cout << "Value deleted from stack " << endl;
        }
    }
    int peek(){
        if(top == -1){
            cout << "Stack is empty "<< endl;
            return 0;
        }else{
            return arr[top];
        }
    }
    bool empty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
    void displayStack(){
        if(top == -1){
            cout << "Stack is empty " << endl;
            return;
        }else{
            for(int i = top ; i >= 0; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

};
int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    
    s.displayStack(); 
    
    cout << "Top element: " << s.peek() << endl;
    
    s.pop();
    s.displayStack(); 

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}