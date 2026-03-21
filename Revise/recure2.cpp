#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &candidates, int target, int index, vector<int> &current, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }

    if (index >= candidates.size() || target < 0)
    {
        return;
    }

    current.push_back(candidates[index]);
    solve(candidates, target - candidates[index], index, current, result);

    current.pop_back();
    solve(candidates, target, index + 1, current, result);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> current;

    solve(candidates, target, 0, current, result);

    return result;
}

void solveP(int n,
            int open,
            int close,
            string current,
            vector<string> &result)
{
    if (current.length() == 2 * n)
    {
        result.push_back(current);
        return;
    }

    if (open < n)
    {
        solveP(n, open + 1, close, current + '(', result);
    }
    if (close < open)
    {
        solveP(n, open, close + 1, current + ')', result);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> result;
    solveP(n, 0, 0, "", result);
    return result;
}

int main()
{

    // vector<int> candidates = {2, 3, 5};
    // int target = 8;

    // vector<vector<int>> ans = combinationSum(candidates, target);

    // for (auto &comb : ans)
    // {
    //     cout << "{ ";
    //     for (int num : comb)
    //         cout << num << " ";
    //     cout << "}" << endl;
    // }

    int n = 4;
    vector<string> ans = generateParenthesis(n);

    cout<<ans.size();
    for (auto &s : ans)
        cout << s << endl;

    return 0;
}