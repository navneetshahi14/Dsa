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

int solve(vector<int> &nums, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    int inclu = solve(nums, n - 2) + nums[n];
    int excl = solve(nums, n - 1) + 0;

    return max(inclu, excl);
}

int solveTD(vector<int> &nums, int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int inclu = solveTD(nums, n - 2, dp) + nums[n];
    int excl = solveTD(nums, n - 1, dp) + 0;

    dp[n] = max(inclu, excl);

    return dp[n];
}

int solveBU(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = nums[i];

        if (i > 1)
            incl += dp[i - 2];
        int excl = dp[i - 1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}

int solveSO(vector<int> &nums)
{

    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = nums[i];

        if (i > 1)
            incl += prev2;
        int excl = prev1 + 0;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    // int ans = solve(nums, n - 1);
    // return ans;

    // vector<int> dp(n, -1);
    // return solveTD(nums, n-1, dp);

    // return solveBU(nums);

    return solveSO(nums); 
}

int main()
{

    vector<int> nums = {9, 9, 8, 2};

    cout << "max non adjcent sum is " << maxNonAdjSum(nums) << endl;

    return 0;
}