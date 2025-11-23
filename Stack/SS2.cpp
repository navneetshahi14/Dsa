#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    solve(s, x);
    s.push(top);
}

stack<int> pushToBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

void sol(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();
    sol(s);
    s.push(top);
}

void reverseAStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();
    reverseAStack(s);
    pushToBottom(s, top);
}

void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    sortedInsert(s, n);

    s.push(n);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, num);
}

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '/' || top == '*')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                {
                    return true;
                }

                st.pop();
            }
        }
    }

    return false;
}

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";
}

int main()
{

    stack<int> s;

    for (int i = 1; i <= 5; i++)
    {
        s.push(i);
    }

    printStack(s);

    pushToBottom(s, 9);

    printStack(s);

    reverseAStack(s);

    printStack(s);

    reverseAStack(s);

    printStack(s);

    sortStack(s);

    printStack(s);

    string str = "(a+(a+b))";

    if(findRedundantBrackets(str)){
        cout<<"It is Redundant"<<endl;
    }else {
        cout<<"It is not Redundant"<<endl;
    }


    return 0;
}