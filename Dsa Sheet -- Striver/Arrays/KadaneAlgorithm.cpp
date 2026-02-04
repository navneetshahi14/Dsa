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

class Solution
{
public:
    int maxSubarray(vector<int> &arr)
    {
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                int sum = 0;

                for (int k = i; k < j; k++)
                {
                    sum += arr[k];
                }

                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};

int main()
{
    vector<int> arr = {2, 3, 5, -2, 7, -4};
    // vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // create an instance of Solution class
    Solution sol;

    int maxSum = sol.maxSubarray(arr);

    // Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}