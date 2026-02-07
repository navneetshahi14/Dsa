#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{

    vector<int> arr = {2, 5, 1, 3, 6, 10};

    int maxi = INT_MIN;
    int secondMaxi = -1;

    for (int i = 0; i < arr.size(); i++)
    {

        if (maxi < arr[i])
        {
            secondMaxi = maxi;
            maxi = arr[i];
        }
    }

    cout << "Largest Element is " << maxi << endl;
    cout << "Second largest element is " << secondMaxi << endl;

    return 0;
}