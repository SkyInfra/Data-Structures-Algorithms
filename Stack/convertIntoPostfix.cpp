#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}

bool isOperand(char ch){
    return (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9');
}

string convertIntoPostfix(string exp){
    string res = "";
    stack<char> st;

    for(char ch : exp){
        if(isOperand(ch)){
            res += ch;
        } else if(ch == '('){
            st.push(ch);
        } else if(ch == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); 
        } else {
            while(!st.empty() && precedence(st.top()) >= precedence(ch)){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;
}

int main(){
    string exp = "A+B*C-D";
    string output = convertIntoPostfix(exp);
    cout << "Postfix: " << output << endl;
    return 0;
}
