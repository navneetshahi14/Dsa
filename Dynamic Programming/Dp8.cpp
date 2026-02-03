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

int solveTD(vector<int> &weight, vector<int> &value, int index, int capacity,vector<int> &dp)
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

int knapSack(vector<int> &weight, vector<int> &value, int n, int max)
{
    return solve(weight, value, n - 1, max);
}

int main()
{

    return 0;
}