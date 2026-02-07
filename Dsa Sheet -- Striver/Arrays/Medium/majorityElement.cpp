#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        pair<int, int> max = make_pair(nums[0], 1);
        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            int current = nums[i];
            if (current == max.first)
            {
                max.second++;
            }
            else if (current != max.first)
            {
                max.second--;
            }

            if (max.second == 0)
            {
                max = make_pair(current, 1);
            }
        }

        return max.first;
    }
};

int main()
{

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;

    int ans = sol.majorityElement(nums);

    cout << "Majority Element more than n/2 times is " << ans << endl;
    return 0;
}