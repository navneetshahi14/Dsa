#include <bits/stdc++.h>
using namespace std;

int kthsmallest(vector<int> &arr, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);

        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

int kthlargest(vector<int> &arr,int k){
    int n = arr.size();

    priority_queue<int,vector<int> , greater<int> > pq;

    for(int i = 0;i<n;i++)
    {
        pq.push(arr[i]);

        if(pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

int main()
{

    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;

    cout << kthsmallest(arr, k)<<endl;

    cout<< kthlargest(arr,2);
    return 0;
}