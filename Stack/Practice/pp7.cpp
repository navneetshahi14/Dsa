#include <iostream>
#include <stack>
using namespace std;

string prefixToInfix(string s)
{
    stack<string> st;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--)
    {
        char c = s[i];

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
    string prefix = "*-A/BC-/AKL";
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;

    return 0;
}