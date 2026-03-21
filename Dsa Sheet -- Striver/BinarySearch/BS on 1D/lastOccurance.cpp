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
    int solve(int n, int key, vector<int> &v)
    {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (v[mid] == key)
            {
                ans = mid;
                low = mid + 1;
            }

            else if (v[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
int main()
{
    int n = 7;
    int key = 13;
    // define sorted array
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};
    // print last occurrence index (or -1)
    Solution sol;
    cout << sol.solve(n, key, v) << "\n";

    return 0;
}