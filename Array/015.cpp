#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getPairs(vector<int> &arr)
{
    unordered_set<int> seen;
    set<pair<int, int>> uniqueset;

    for (int num : arr)
    {
        if (seen.count(-num))
        {
            int a = min(-num, num);
            int b = max(-num, num);

            uniqueset.insert({a, b});
        }

        seen.insert(num);
    }

    vector<vector<int>> result;
    for (auto &p : uniqueset)
    {
        result.push_back({p.first, p.second});
    }

    return result;
}

int main()
{

    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = getPairs(arr);

    for (auto &i : res)
    {
        cout << "[" << i[0] << ", " << i[1] << "]" << endl;
    }

    return 0;
}