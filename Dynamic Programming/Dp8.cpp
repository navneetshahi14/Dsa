#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }

    int exclude = 0 + solve(weight, value, index - 1, capacity);

    int ans = max(include, exclude);

    return ans;
}

int solveTD(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveTD(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = 0 + solveTD(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);

    return dp[index][capacity];
}

int solveBU(vector<int> &weight, vector<int> &value, int index, int capacity)
{

    vector<vector<int>> dp(index, vector<int>(capacity + 1, 0));

    for (int i = weight[0]; i <= capacity; i++)
    {
        if (weight[0] <= capacity)
            dp[0][i] = value[0];
        else
            dp[0][i] = 0;
    }

    for (int n = 1; n < index; n++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[n] <= w)
            {
                include = value[n] + dp[n - 1][w - weight[n]];
            }

            int exclude = 0 + dp[n - 1][w];

            dp[n][w] = max(include, exclude);
        }
    }

    return dp[index - 1][capacity];
}

int knapSack(vector<int> &weight, vector<int> &value, int n, int max)
{
    // return solve(weight, value, n - 1, max);

    // vector<vector<int>> dp(n, vector<int>(max + 1, -1));
    // return solveTD(weight, value, n - 1, max, dp);

    return solveBU(weight, value, n - 1, max);
}

int main()
{

    // vector<int> weight = {6,5,1,5,6,5,9};
    // vector<int> value = {5,3,4,9,6,1,1};
    // int n = 7;
    // int max = 63;

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int n = 4;
    int max = 5;

    int ans = knapSack(weight, value, n, max);
    cout << "Answer is " << ans << endl;

    return 0;
}