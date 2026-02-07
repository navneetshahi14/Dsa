#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    int n = arr.size();
    int key = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = key;

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}