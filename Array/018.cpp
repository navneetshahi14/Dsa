#include<bits/stdc++.h>
using namespace std;

bool subArrayExist(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> s;

    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];

        if(sum == 0 || s.count(sum))
        {
            return true;
        }
        s.insert(sum);
    }

    return false;

}

int main() {

    vector<int> arr = {4, 2, -3, 1, 6};

    if(subArrayExist(arr)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
 
return 0;
}