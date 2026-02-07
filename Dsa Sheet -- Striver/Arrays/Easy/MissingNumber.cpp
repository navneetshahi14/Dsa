#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        int s = (n * (n + 1)) / 2;

        return s - sum;
    }
};

int main()
{

    int N = 5;
    vector<int> a = {1, 2, 4, 5};

    Solution obj;
    int ans = obj.missingNumber(a);
    cout << "The missing number is: " << (N -(-1*ans)) << endl;

    return 0;
}