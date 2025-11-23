#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& interval)
{
    vector<vector<int>> ans;

    sort(interval.begin(),interval.end());
    vector<int> current = interval[0];

    for(int i = 1;i<interval.size();i++)
    {
        if(current[1] >= interval[i][0])
        {
            current[1] = max(current[1],interval[i][1]);
        }
        else {
            ans.push_back(current);
            current = interval[i];
        }
    }

    ans.push_back(current);

    return ans;
}

int main() {
 
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};


return 0;
}