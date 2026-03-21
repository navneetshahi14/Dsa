#include <iostream>
#include <vector>
using namespace std;

int func(int ind, int sum, vector<int> &nums)
{
    if (sum == 0)
        return 1;

    if (sum < 0 || ind == nums.size())
        return 0;

    return func(ind + 1, sum - nums[ind], nums) + func(ind + 1, sum, nums);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int target)
{
    return func(0, target, nums);
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    cout << "Number of subsequences with target sum " << target << ": "
         << countSubsequenceWithTargetSum(nums, target) << endl;

    return 0;
}