#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    // code here
    unordered_set<int> s;

    for (int i : a)
    {
        s.insert(i);
    }
    for (int i : b)
        s.insert(i);

    vector<int> ans;
    for (auto an : s)
    {
        ans.push_back(an);
    }

    return ans;
}

int main()
{

    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> ans = findUnion(a,b);

        for (auto num: ans) {
        cout << num << " ";
    }
    cout<<endl;

    return 0;
}