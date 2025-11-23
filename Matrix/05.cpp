#include <bits/stdc++.h>
using namespace std;

void rotate90(vector<vector<int>> &mat)
{
    int n = mat.size();

    vector<vector<int>> res(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - i - 1] = mat[i][j];
        }
    }

    mat = res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    rotate90(mat);
    for (auto &row : mat)
    {
        for (int x : row)
        {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}