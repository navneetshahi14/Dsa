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
    int lowerBound(vector<int> arr, int target)
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

    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();
    int x = 9;

    Solution finder;
    int ind = finder.lowerBound(arr, x);

    cout << "The lower bound is the index: " << ind << "\n";

    return 0;
}