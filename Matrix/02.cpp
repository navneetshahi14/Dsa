#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
        bool BinarySearch(vector<vector<int>> matrix,int target)
        {
            int row = matrix.size();
            int col = matrix[0].size();

            int left = 0;
            int right = row*col -1;

            while(left <= right)
            {
                int mid = left + (right - left)/2;
                int element = matrix[mid/col][mid%col];

                if(element == target) return true;
                else if(element > target) right = mid - 1;
                else left = mid +1;
            }

            return false;
        }

};

int main() {
 
    vector<vector<int>> mat = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

    Solution sol;
    if(sol.BinarySearch(mat,3)){
        cout<<"Found!!!"<<endl;
    }
    else cout<<"Not Found!!!"<<endl;

return 0;
}