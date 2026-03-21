#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int stockbuySell(vector<int> &prices)
    {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};

int main()
{
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.stockbuySell(prices) << endl;

    return 0;
}