#include <bits/stdc++.h>
using namespace std;

// Merging two heaps
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a,vector<int> &b,int n,int m)
{

    vector<int> ans;

    for(int i = n/2;i> 0;i--){
        heapify(ans,n,i);
    }

    return ans;
}

int main()
{

    return 0;
}