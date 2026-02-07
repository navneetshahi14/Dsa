#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{

    vector<int> arr = {2, 5, 1, 3, 10};

    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    cout << "Largest Element is " << maxi << endl;

    return 0;
}