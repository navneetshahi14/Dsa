#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr)
{
    int i = 0, j = 0;
    while (j < arr.size())
    {
        if (arr[j] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
        j++;
    }
    j = i;
    while (j < arr.size())
    {
        if (arr[j] == 1)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}

void printArray(vector<int> &arr)
{
    for(int i = 0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    vector<int> arr = {0, 1, 2, 0, 1, 2};

    sort012(arr);
    printArray(arr);

    return 0;
}