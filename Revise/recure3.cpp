#include <iostream>
#include <vector>
using namespace std;

void helper(string &s, int index, string curr, vector<string> &result)
{
    if (index == s.size())
    {
        result.push_back(curr);
        return;
    }

    // exclude
    helper(s, index + 1, curr, result);

    // include
    helper(s, index + 1, curr + s[index], result);

    curr.pop_back();
}

vector<string> getSubsequences(string s)
{
    vector<string> result;
    string current = "";
    helper(s, 0, current, result);
    return result;
}

int main()
{
    string s = "abc";

    vector<string> subsequences = getSubsequences(s);

    for (auto &subseq : subsequences)
    {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}