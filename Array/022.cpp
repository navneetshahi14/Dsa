#include <bits/stdc++.h>
using namespace std;

void morethanNbyK(vector<int> &arr, int k)
{
    int n = arr.size();
    int x = n / k;

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second > x)
        {
            cout << i.first << endl;
        }
    }
}

int main()
{

    vector<int> arr = {3, 4, 2, 2, 1, 2, 3, 3};
    int k = 4;
    morethanNbyK(arr, k);

    return 0;
}