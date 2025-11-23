#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();

        vector<int> ans;

        int startRow = 0;
        int startCol = 0;
        int endRow = row - 1;
        int endCol = col - 1;

        int count = 0;
        int total = row * col;

        while (count < total)
        {
            for (int index = startCol; count < total && index <= endCol; index++)
            {
                ans.push_back(mat[startRow][index]);
                count++;
            }
            startRow++;

            for (int index = startRow; count < total && index <= endRow; index++)
            {
                ans.push_back(mat[index][endCol]);
                count++;
            }
            endCol--;

            for (int index = endCol; count < total && index >= startCol; index--)
            {
                ans.push_back(mat[endRow][index]);
                count++;
            }
            endRow--;

            for (int index = endRow; count < total && index >= startRow; index--)
            {
                ans.push_back(mat[index][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

int main()
{

    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    Solution sol;

    vector<int> ans = sol.spirallyTraverse(mat);

    cout << "[ ";
    for (int i : ans)
    {
        cout << i << " ";
    }

    cout << "]" << endl;

    return 0;
}