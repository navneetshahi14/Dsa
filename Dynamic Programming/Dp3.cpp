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

int solveRec(vector<int> &coins, int x)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveRec(coins, x - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

int solveTD(vector<int> &coins, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;
    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solveRec(coins, x - coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    dp[x] = mini;

    return mini;
}

int solveBU(vector<int> &coins, int x)
{
    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    if(dp[x] == INT_MAX) return -1;

    return dp[x];   
}

int minimumElements(vector<int> &coins, int x)
{

    // int ans = solveRec(coins,x);
    // if (ans == INT_MAX){
    //     return -1;
    // }
    // return ans;

    // int n = coins.size();
    // vector<int> dp(x + 1, -1);
    // int ans = solveTD(coins, x, dp);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // else
    // {
    //     return ans;
    // }

    return solveBU(coins,x);
}
int main()
{

    vector<int> coins = {1, 2, 3};
    int x = 7;

    cout << "The minimum coins are " << minimumElements(coins, x) << endl;

    return 0;
}