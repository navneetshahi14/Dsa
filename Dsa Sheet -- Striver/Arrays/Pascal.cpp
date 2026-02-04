#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution
{

public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }

        return ans;
    }

    // using binomial therom

    vector<long long> generateByBinomial(int numRows)
    {
        vector<long long> ans;

        long long val = 1;
        ans.push_back(val);

        for (int i = 1; i < numRows; i++)
        {
            val = val * (numRows - i) / i;
            ans.push_back(val);
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> ans = sol.generate(5);

    for (auto i : ans)
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << " ,";
        }

        cout << "},";
    }
    cout<<endl;

    vector<long long> ansBinomial = sol.generateByBinomial(5);

    for(auto i:ansBinomial){
        cout<<i<<" ";
    }

    cout<<endl;

    return 0;
}