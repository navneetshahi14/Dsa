#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int currSum = arr[0];
        int maxSum = arr[0];
        int n = arr.size();
        
        for(int i = 1;i<n;i++)
        {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum,currSum);
        }
        
        return maxSum;
    }
};

int main() {
 
    Solution sol;

    vector<int> arr = {5, 4, 1, 7, 8};
    cout<<" The Answer is "<<sol.maxSubarraySum(arr)<<endl;

return 0;
}