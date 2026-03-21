#include <iostream>
#include <stack>
using namespace std;

string postfixToprefix(string postfix)
{
    stack<string> st;
    int n = postfix.length();

    for (int i = 0; i < n; i++)
    {
        char ch = postfix[i];

        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            st.push(ch + op1 + op2);
        }
    }
    return st.top();
}

int main()
{
    string postfix = "ABC/-AK/L-*";
    cout << "Prefix Expression: " << postfixToprefix(postfix) << endl;
    return 0;
}