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
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int posIndex = 0;
        int negIndex = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
            else
            {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {28, -41, 22, -8, -37, 46, 35, -9, 18, -6, 19, -26, -37, -10, -9, 15, 14, 31};

    vector<int> ans = sol.rearrangeArray(nums);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}