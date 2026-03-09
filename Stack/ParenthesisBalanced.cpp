#include <iostream>
#include <stack>
using namespace std;
int main()
{
   string exp = "{[()]}";
    stack<char> st;
    for(char ch : exp)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (st.empty())
            {
                cout << "Not Balanced " << endl;
                return 0;
            }
            else
            {
                if (st.top() == '(' && ch == ')' || st.top() == '{' && ch == '}' || st.top() == '[' && ch == ']')
                {
                    st.pop();
                }
                else
                {
                    cout << "Not Balanced " << endl;
                    return 0;
                }
            }
        }
        else
        {
            cout << "not Balanced " << endl;
            return 0;
        }
    }
    if (st.empty())
    {
        cout << "Balanced " << endl;
    }
    else
    {
        cout << "not Balanced " << endl;
    }
    return 0;
}