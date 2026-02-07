#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> arr = {1, 2, 3, 7, 5, 6};
    bool isSorted = true;

    for (int i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i - 1])
            isSorted = false;

    if (isSorted)
        cout << "Yes Sorted!!" << endl;
    else
        cout << "Not Sorted!!" << endl;

    return 0;
}