#include <bits/stdc++.h>
using namespace std;

bool hasTriplet(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int left = i+1;
        int right = n-1;

        while(left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            if(sum == target) return true;
            else if (sum < target) left++;
            else right--;
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int k = 14;
    if(hasTriplet(arr,k))cout<<"True"<<endl;
    else cout<<"False"<<endl;

    return 0;
}