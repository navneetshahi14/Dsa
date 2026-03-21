#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    // for(int i = 0;i<n;i++){
    //     for(int j = i+1;j<n;j++){
    //         if(nums[i] + nums[j] == target){
    //             return {i,j};
    //         }
    //     }
    // }

    // return {};

    for (int i = 0; i < n; i++)
    {
        int completion = target - nums[i];

        if (mp.find(completion) != mp.end())
        {
            return {mp[completion], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main()
{

    return 0;
}