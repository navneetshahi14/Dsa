#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    vector<int> arr = {2, 7, 11, 15};

    int n = arr.size();
    int i = 0, j = n - 1;

    sort(arr.begin(), arr.end());

    int target = 10;

    while (i <= j)
    {
        int sum = arr[i] + arr[j];
        if (sum > target)
        {
            j--;
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            cout << "Found !!!" << endl;
            break;
        }
    }

    return 0;
}