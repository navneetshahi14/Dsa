#include <bits/stdc++.h>
using namespace std;

// reverse string using stack
void reverseString(string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }

    str = "";

    while (!st.empty())
    {
        char top = st.top();
        str += top;
        st.pop();
    }
}

void solve(stack<int> &inputStack, int count, int size)
{
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int top = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, size);
    inputStack.push(top);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

bool matches(char top, char ch){
    return ((ch == ')' && top == '(') || (ch == '}' && top == '{' ) || ( ch == ']' && top == '['));
}

bool isValidParenthisis(string exp)
{
    stack<char> st;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }else{
            if(!st.empty()){
                char top = st.top();
                if(matches(top,ch)){
                    st.pop();
                }else{
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        cout << top << " ";
    }
    cout << endl;
}

int main()
{

    // stack<int> st;
    // for (int i = 1; i <= 5; i++)
    // {
    //     st.push(i);
    // }
    // cout << st.top() << endl;

    // printStack(st);

    // deleteMiddle(st, st.size());

    // printStack(st);

    string exp = "({[([])]})";

    if(isValidParenthisis(exp)){
        cout<<"It is a valid parenthesis"<<endl;
    }else{
        cout<<"It is not a valid parenthesis"<<endl;
    }

    return 0;
}