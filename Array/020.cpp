#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr)
{
    unordered_set<int> s(arr.begin(),arr.end());
    int longest = 0;

    for(int i:s){
        if(s.find(i-1) == s.end())
        {
            int currentNum = i;
            int currentStreak = 1;

            while(s.find(currentNum+1) != s.end())
            {
                currentNum++;
                currentStreak++;
            }

            longest = max(longest,currentStreak);
        }
    }

    return longest;
}

int main() {

    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};

    cout<<"The longest Consecutive numbers are "<<longestConsecutive(arr)<<endl;
 
return 0;
}