#include <iostream>
#include <vector>
using namespace std;

// Print
// 1 to 100;

void print1To100(int n)
{
    if (n == 0)
        return;
    print1To100(n - 1);
    cout << n << " ";
}

// 100 to 1;

void print100To1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    print100To1(n - 1);
}

// factorial
int factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

// power
int pow(int n, int x)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    return x * pow(n - 1, x);
}

void reverse(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

// sum of digits
int summingdig(int num, int sum)
{
    if (num == 0)
        return sum;

    sum = num % 10 + sum;
    summingdig(num / 10, sum);
}

// check palindrome
bool checkPali(string s, int start, int end)
{
    if (start >= end)
        return true;

    if (s[start] != s[end])
        return false;

    checkPali(s, start + 1, end - 1);
}

// binary Search
int BSearch(vector<int> &arr, int start, int end, int k)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

    if (arr[mid] == k)
    {
        return mid;
    }

    if (arr[mid] < k)
    {
        return BSearch(arr, mid + 1, end, k);
    }
    else
    {
        return BSearch(arr, start, mid - 1, k);
    }
}

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

void solve(vector<int> &nums, int index, vector<vector<int>> &results, vector<int> &current)
{
    // base case
    if (index == nums.size())
    {
        results.push_back(current);
        return;
    }

    solve(nums, index + 1, results, current);

    current.push_back(nums[index]);
    solve(nums, index + 1, results, current);

    current.pop_back();
}

vector<vector<int>> subset(vector<int> &nums)
{
    vector<vector<int>> results;
    vector<int> current;

    solve(nums, 0, results, current);

    return results;
}

// permutation

void solve(vector<int> &nums,
           vector<bool> &visited,
           vector<int> &current,
           vector<vector<int>> &result)
{
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        current.push_back(nums[i]);

        solve(nums, visited, current, result);

        current.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited(nums.size(), false);

    solve(nums, visited, current, result);

    return result;
}



int main()
{
    // print100To1(10);
    // int fac = factorial(10);
    // cout << endl
    //      << fac << endl;
    // int p = pow(2, 2);
    // cout << p << endl;

    // vector<int> arr = {1, 2, 3, 4, 5, 6};
    // reverse(arr, 0, arr.size() - 1);

    // for (int i : arr)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // int sum = 0;
    // int num = 123;
    // int ans = summingdig(num, sum);
    // cout << ans << endl;

    // string s = "navneet";
    // if (checkPali(s, 0, s.length() - 1))
    // {
    //     cout << "Yes" << endl;
    // }
    // else
    // {
    //     cout << "No" << endl;
    // }

    // cout<<BSearch(arr,0,arr.size()-1,7)<<endl;
    // cout << fib(5) << endl;

    // vector<int> nums = {1, 2, 3};

    // vector<vector<int>> ans = subset(nums);

    // for (auto subset : ans)
    // {
    //     cout << "{ ";
    //     for (int x : subset)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << "}" << endl;
    // }

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for (auto &p : ans)
    {
        for (int x : p)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}