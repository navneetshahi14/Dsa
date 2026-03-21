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

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> res(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            res[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }

        ans.push_back(res);
    }
    return ans;
}

int main()
{

    int n = 5;

    vector<vector<int>> result = generate(n);
    for (auto &row : result)
    {
        cout<<"[ ";
        for (auto &val : row)
            cout << val << " ";
        cout <<"]"<< endl;
    }

    return 0;
}