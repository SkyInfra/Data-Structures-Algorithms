#include <iostream>
#include <stack>
using namespace std;

void palindrome(string exp){
    stack<char> st;
    for(char ch : exp){
        st.push(ch);
    }

    string rev = "";
    while(!st.empty()){
        rev += st.top();
        st.pop();
    }

    if(rev == exp){
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl; 
    }
}

int main(){
    palindrome("haseeb");
    return 0;
}