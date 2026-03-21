#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findSums(int ind, int currentSum, vector<int> &arr, vector<int> &sums)
{
    if (ind == arr.size())
    {
        sums.push_back(currentSum);
        return;
    }

    findSums(ind + 1, currentSum + arr[ind], arr, sums);

    findSums(ind + 1, currentSum, arr, sums);
}

vector<int> subsetSums(vector<int> &arr)
{
    vector<int> sums;
    findSums(0, 0, arr, sums);
    // sort(sums.begin(), sums.end()); // Sort in increasing order
    return sums;
}

int main()
{
    vector<int> arr = {5, 2, 1};
    vector<int> result = subsetSums(arr);
    cout<<"answer"<<endl;
    for (int sum : result)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}