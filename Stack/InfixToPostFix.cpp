#include <iostream>
#include <stack>
using namespace std;
int Precedance(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
bool isOperand(char ch)
{
    return (
        ch >= 'A' && ch <= 'Z' ||
        ch >= 'a' && ch <= 'z' ||
        ch >= '1' && ch <= '9');
}
string PostFix(string exp)
{
    stack<char> st;
    string output = "";
    for (char ch : exp)
    {
        if (isOperand(ch))
        {
            output += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && Precedance(st.top()) >= Precedance(ch))
            {
                output += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }
    return output;
}
int main()
{
    string output = PostFix("A+B*C-D/E");
    cout << output << endl;
    return 0;
}