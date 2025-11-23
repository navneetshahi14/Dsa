#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<int> profit(n, 0);

    int maxPrice = prices[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        maxPrice = max(maxPrice, prices[i]);
        profit[i] = max(profit[i + 1], maxPrice - prices[i]);
    }

    int res = 0;
    int minPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        res = max(res, profit[i] + (prices[i] - minPrice));
    }

    return res;
}

int main()
{
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices)<<endl;
    return 0;
}