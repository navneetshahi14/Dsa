#include <bits/stdc++.h>
using namespace std;

#define MAX 5000

class Solution
{
private:
    vector<int> nextSmallerElement(vector<int> &arr, int n)
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

    int largestRectangleArea(vector<int> &heights, int n)
    {

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

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

public:
    int maxArea(vector<vector<int>> M, int n, int m)
    {
        // compute area for first row
        int area = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // row update: by adding previous row's value
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            // entire row is updated now
            area = max(area, largestRectangleArea(M[i], m));
        }

        return area;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> M = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    int n = M.size();
    int m = M[0].size();

    cout << "The answer is " << sol.maxArea(M, 4, 4) << endl;

    return 0;
}