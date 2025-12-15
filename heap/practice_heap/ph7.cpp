#include <bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int> &arr, int k)
{
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    int i;

    for (i = k; i < n; i++)
    {
        pq.push(arr[i]);

        arr[i - k] = pq.top();
        pq.pop();
    }

    while (!pq.empty())
    {
        arr[i - k] = pq.top();
        pq.pop();
        i++;
    }
}

int main()
{

    vector<int> arr = {2, 3, 1, 4};
    int k = 2;
    nearlySorted(arr, k);
    for (int x : arr)
        cout << x << ' ';

    return 0;
}