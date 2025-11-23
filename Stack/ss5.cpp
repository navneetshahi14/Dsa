#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallestElement(vector<int> &arr, int n)
{
    stack<int> st;

    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;

    st.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallestElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

bool knows(vector<vector<int>> &M,int a , int b,int n){
    if(M[a][b] == 1){
        return true;
    }else{
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (knows(M,a, b,n))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    int candidate = st.top();
    bool rowCheck = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }

    if(zeroCount == n){
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for(int i = 0;i<n;i++){
        if(M[i][candidate] == 1)
        {
            oneCount++;
        }
    }

    if(oneCount == n-1){
        colCheck = true;
    }

    if(rowCheck == true && colCheck == false)
    {
        return true;
    }

    return false;
} 

int main()
{

    vector<int> heights = {2, 4};
    int ans = largestRectangleArea(heights);

    cout << "The answer is " << ans << endl;

    return 0;
}