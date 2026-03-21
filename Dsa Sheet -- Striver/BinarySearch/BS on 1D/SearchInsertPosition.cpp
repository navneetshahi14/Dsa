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
    int searchInsertPosition(vector<int> arr, int target)
    {
        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};
int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;

    Solution sol;
    int ans = sol.searchInsertPosition(arr, x);

    cout << " Search Insert Position " << ans << endl;

    return 0;
}