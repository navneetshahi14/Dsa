#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int nonZeroIndex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}

int main()
{

    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    // Print the result
    for (int num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}