#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr)
{
    // code here
    int last = arr[arr.size()-1];
    for(int i = arr.size()-1;i>=0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5};

    rotate(arr);
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}