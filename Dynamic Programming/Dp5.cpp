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

int solve(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = nums[i];
        if (i > 1)
        {
            incl += prev2;
        }

        int excl = prev1 + 0;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    vector<int> first, second;

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            first.push_back(valueInHouse[i]);
        }
        if (i != 0)
            second.push_back(valueInHouse[i]);
    }

    return max(solve(first),solve(second));
}

int main()
{

    return 0;
}