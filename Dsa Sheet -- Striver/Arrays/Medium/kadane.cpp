#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxSubArray(vector<int> arr)
{
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{

    vector<int> arr = {2, 3, 5, -2, 7, -4};

    int ans = maxSubArray(arr);

    cout << "Answer: " << ans << endl;

    return 0;
}