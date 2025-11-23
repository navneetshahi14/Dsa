#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left <= right)
    {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex > k)
            return quickSelect(arr, left, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, right, k);
    }

    return -1;
}

int kthSmallest(vector<int> &arr, int k)
{
    return quickSelect(arr, 0, arr.size()-1, k);
}

int main()
{

    vector<int> arr = {8, 4, 5, 3, 1, 6, 7, 2};
    int k = 5;

    cout << "Kth smallest element is " << kthSmallest(arr, k) << endl;
    return 0;
}