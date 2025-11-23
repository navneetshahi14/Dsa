#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &ans,vector<int> output,vector<int> nums,int index){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(ans,output,nums,index+1);

    // include
    int element = nums[index];
    output.push_back(element);

    solve(ans,output,nums,index+1);

}

vector<vector<int>> subsets(vector<int> nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(ans,output,nums,index);

    return ans;
}

int main() {

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> n = subsets(nums);

    for(int i = 0;i<n.size();i++){
        cout<<"{ ";
        for(auto j:n[i]){
            cout<<j<<" ";
        }
        cout<<"}\n";
    }
 
return 0;
}   