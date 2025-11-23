#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans,vector<int> nums,int index)
{
    // base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j =0;j<nums.size();j++)
    {
        swap(nums[index],nums[j]);
        solve(ans,nums,index+1);
        // backtracking
        swap(nums[j],nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    int index = 0;
    solve(ans,nums,index);

    return ans;
}

int main() {

    vector<int> nums = {1,2,3};

    vector<vector<int>> n = permute(nums);

    for(int i = 0;i<n.size();i++)
    {
        for(auto s:n[i]){
            cout<<s<<" ";
        }
        cout<<endl;
    }
 
return 0;
}