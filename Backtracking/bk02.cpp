#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

void addSolution(int n, vector<vector<int>> &board, vector<vector<int>> &ans)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }

        y--;
    }

    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;

    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans)
{
    if (col == n)
    {
        addSolution(n, board, ans);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, n, board, ans);

            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, n, board, ans);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueens(n);

    cout << "Total solutions: " << ans.size() << endl;

    for (int s = 0; s < ans.size(); s++)
    {
        cout << "Solution " << s + 1 << ":\n";
        for (int i = 0; i < n * n; i++)
        {
            cout << ans[s][i] << " ";
            if ((i + 1) % n == 0)
                cout << endl;
        }
        cout << endl;
    }

    return 0;
}