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
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> result;

    int top = 0;
    int left = 0;
    int right = n - 1;
    int bottom = n - 1;

    while (top <= bottom && left <= right)
    {
        // top

        for (int i = left; i <= right; i++)
        {
            result.push_back(matrix[top][i]);
        }
        top++;

        // right

        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        // bottom

        for (int i = right; i >= left; i--)
        {
            result.push_back(matrix[bottom][i]);
        }
        bottom--;

        // left
        for (int i = bottom; i >= top; i--)
        {
            result.push_back(matrix[i][left]);
        }
        left++;
    }

    return result;
}
int main()
{

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    vector<int> result = spiralOrder(matrix);

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}