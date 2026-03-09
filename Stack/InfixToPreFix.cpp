#include <iostream>
using namespace std;
#include <stack>
int Precedance(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
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
string posFix(string exp)
{
    stack<char> st;
    string output;
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
string reverse(string exp)
{
    stack<char> st;
    string rev = "";
    for (char ch : exp)
    {
        st.push(ch);
    }
    while (!st.empty())
    {
        rev += st.top();
        st.pop();
    }
    return rev;
}
int main()
{
    string exp = "A+B*C-D/E";
    string rev = reverse(exp);
    string pos = posFix(rev);
    string result = reverse(pos);
    cout << result << endl;
    return 0;
}