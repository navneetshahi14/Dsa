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
    vector<int> leaders(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i < n - 1; i++)
        {
            int current = nums[i];
            bool a = false;
            for (int j = i + 1; j < n; j++)
            {
                if (current < nums[j])
                {
                    a = true;
                    break;
                }
            }

            if (!a)
            {
                ans.push_back(current);
            }
        }
        ans.push_back(nums[n - 1]);

        return ans;
    }

    vector<int> optimalLeader(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        ans.push_back(nums[n - 1]);
        int max = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (max < nums[i])
            {
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    vector<int> nums = {4, 7, 1, 0};

    Solution sol;

    vector<int> ans = sol.optimalLeader(nums);

    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}