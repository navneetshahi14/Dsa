#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        
        int low = 1, high = 1e9;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int count = 0;
            
            for(int i = 0;i < row;i++)
            {
                count += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
            }
            
            if(count < (row* col + 1) /2){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return low;
    }
};


int main() {


    vector<vector<int>> mat = {{1,3,5},{2,6,9},{3,6,9}};

    Solution sol;

    cout<<"The median is "<<sol.median(mat)<<endl;
    
 
return 0;
}