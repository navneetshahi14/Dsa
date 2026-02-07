#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr, int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);

        low++;
        high--;
    }
}

vector<int> rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();

    if (n == 0 || k == 0)
        return arr;

    k = k % n;

    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);

    return arr;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    vector<int> result = rotateArray(arr, 2);

    for (int i : result)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}