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

int fib(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    return dp[n];
}

int fibBU(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibSO(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{

    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << "Top Down Approach(Recursion+Memoization) " << fib(n, dp) << endl;
    cout << "Bottom Up Approach(Tabulation) " << fibBU(n) << endl;
    cout << "Space Optimization " << fibSO(n) << endl;

    return 0;
}