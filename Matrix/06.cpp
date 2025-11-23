#include <bits/stdc++.h>
using namespace std;

void printCommonElements(vector<vector<int>> &mat)
{
    unordered_map<int, int> mp;

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        mp[(mat[0][i])] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp[(mat[i][j])] == i)
            {
                mp[(mat[i][j])] = i + 1;

                if (i == m - 1 && mp[(mat[i][j])] == m)
                {
                    cout << mat[i][j] << " ";
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    printCommonElements(mat);

    return 0;
}