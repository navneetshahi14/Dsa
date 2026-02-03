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

#define MOD 1000000007

long long int solve(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int ans = ((n - 1) % MOD) * (((solve(n - 1) % MOD) + (solve(n - 2) % MOD) % MOD));

    return ans;
}

long long int solveTD(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = ((n - 1) % MOD) * (((solveTD(n - 1, dp) % MOD) + (solveTD(n - 2, dp) % MOD) % MOD));

    return dp[n];
}

long long int solveBD(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i-1] % MOD;
        long long int second = dp[i-2] % MOD;

        long long int sum = (first + second) %MOD;

        long long int ans = ((n-1) * sum) % MOD;

        dp[i] = ans;
    }

    return dp[n];
}

long long int countDerangement(int n)
{
    /*Recusrion*/
    // return solve(3);

    // vector<long long int> dp(n + 1, -1);
    // return solveTD(n, dp);

    return solveBD(n);
}

int main()
{

    cout << "Answer is " << countDerangement(3) << endl;

    return 0;
}