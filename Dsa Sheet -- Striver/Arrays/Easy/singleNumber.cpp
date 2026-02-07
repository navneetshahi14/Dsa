#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {

        int res = 0;

        for (auto num : nums)
        {
            res ^= num;
        }

        return res;
    }
};

int main()
{

    vector<int> arr = {4, 1, 2, 1, 2};

    Solution obj;
    int ans = obj.singleNumber(arr);

    cout << "The single element is: " << ans << endl;

    return 0;
}