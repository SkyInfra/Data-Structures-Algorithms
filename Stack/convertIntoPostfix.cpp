#include <iostream>
#include <stack>
using namespace std;



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
