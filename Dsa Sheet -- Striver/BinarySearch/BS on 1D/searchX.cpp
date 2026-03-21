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
    int BsearchX(vector<int> &arr, int target)
    {
        int low = 0;
        int high = arr.size();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};
int main()
{

    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;

    Solution obj;
    int ind = obj.BsearchX(a, target);

    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: " << ind << endl;

    return 0;

    return 0;
}