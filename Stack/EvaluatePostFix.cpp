
#include <iostream>
#include <stack>
using namespace std;

void solve(string exp){
    stack<int> st; 

    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ' '){
            continue; 
        } else if(isdigit(exp[i])){
            st.push(exp[i] - '0'); 
        } else {
            int first = st.top(); 
            st.pop();
            int sec = st.top();   
            st.pop();

            switch(exp[i]){
                case '+': st.push(sec + first); break;
                case '-': st.push(sec - first); break;
                case '*': st.push(sec * first); break;
                case '/': st.push(sec / first); break;
            }
        }
    }

    cout << "Answer: " << st.top() << endl;
}

int main(){
    string exp = "5 6 2 + * 12 4 / -"; // postfix expression
    solve(exp);
    return 0;
}
