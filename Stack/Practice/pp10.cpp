#include <iostream>
#include <stack>
using namespace std;

string postfixToInfix(string postfix)
{
    stack<string> st;
    int n = postfix.length();
    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];

        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            st.push("(" + op1 + c + op2 + ")");
        }
    }

    return st.top();
}

int main()
{
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;

    return 0;
}