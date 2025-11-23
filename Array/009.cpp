#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if( n == 1 ) return 0;
        
        sort (arr.begin(),arr.end());
        int ans = arr[n-1] - arr[0];
        
        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;
        
        for(int i = 0;i<n-1;i++){
            int minValue = min(smallest,arr[i+1] - k);
            int maxValue = max(largest,arr[i] + k);
            
            if(minValue < 0) continue;
            
            ans = min(ans,maxValue - minValue);
            
        }
        
        return ans;
    }
};

int main() {

    vector<int> ar = {1, 5, 8, 10};

    int k = 2;

    Solution sol;
    cout<<"The answer is "<< sol.getMinDiff(ar,k)<<endl;
 
return 0;
}