#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int a = 0;
    int b = arr.size() - 1;

    while (a <= b)
    {
        swap(arr[a++], arr[b--]);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    reverseArray(arr);

    for (int it : arr)
    {
        cout << it << " ";
    }

    return 0;
}