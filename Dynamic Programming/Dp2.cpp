#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <algorithm>

#define MOD 1000000007
using namespace std;

// int solve(int i, long long nStairs)
// {
//     if (i == nStairs)
//     {
//         return 1;
//     }
//     if (i > nStairs)
//     {
//         return 0;
//     }
//     return (solve(i + 1, nStairs) + solve(i + 2, nStairs)) % MOD;
// }

// int countDistinctWaysToClimbStairs(long long nStairs)
// {
//     int ans = solve(0, nStairs);
// }

int solve(vector<int> &cost, int n)
{
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
    return ans;
}

int solve2(vector<int> &cost, int n, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    if (dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] + min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    return dp[n];
}

int solve3(vector<int> &cost, int n)
{
    vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i <= n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

int solve4(vector<int> &cost, int n)
{
    int prev1 = cost[0];
    int prev2 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int minCostToClimbStairs(vector<int> &cost)
{
    // int n  = cost.size();
    // int ans = min(solve(cost,n-1),solve(cost,n-2));
    // return ans;

    /* Top Down Approach */
    // int n = cost.size();
    // if (n == 1)
    //     return cost[0]; // single element case
    // if (n == 2)
    //     return min(cost[0], cost[1]);
    // vector<int> dp(n + 1, -1);
    // int ans = min(solve2(cost, n - 1, dp), solve2(cost, n - 2, dp));
    // return ans;

    /*Bottom Up Approach*/
    int n = cost.size();
    int ans = solve3(cost,n);
    return ans;

    /* Space Optimization */
    // int n = cost.size();
    // int ans = solve4(cost, n);
    // return ans;
}

void runTest(vector<int> cost, int expected)
{
    int result = minCostToClimbStairs(cost);
    cout << "Cost array: ";
    for (int c : cost)
        cout << c << " ";
    cout << "\nExpected: " << expected << ", Got: " << result;
    if (result == expected)
    {
        cout << " Passed\n\n";
    }
    else
    {
        cout << " Failed\n\n";
    }
}

void testCases()
{
    runTest({10, 15, 20}, 15);
    
    runTest({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6);

    runTest({0, 0, 0, 0}, 0);

    runTest({1, 2, 3, 4, 5}, 6);

    runTest({5}, 5);

    runTest({5, 10}, 5);
}

int main()
{
    testCases();

    return 0;
}