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

// Solution class
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int index = -1;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = nums.size() - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};

    Solution sol;

    sol.nextPermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
