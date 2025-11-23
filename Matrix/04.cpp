#include <bits/stdc++.h>
using namespace std;

int findMax(vector<vector<int>> &mat)
{
    int maxValue = INT_MIN;

    int row = mat.size();
    int col = mat[0].size();

    for (int i = 0; i < col - 1; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            for (int k = i + 1; k < col; k++)
            {
                for (int l = j + 1; l < col; l++)
                {
                    if (maxValue < (mat[k][l] - mat[i][j]))
                    {
                        maxValue = mat[k][l] - mat[i][j];
                    }
                }
            }
        }
    }

    return maxValue;
}

int main()
{

    vector<vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};

    cout << " the answer is " << findMax(mat) << endl;

    return 0;
}