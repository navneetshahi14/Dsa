#include <bits/stdc++.h>
using namespace std;

void printMatrixRowWise(int row, int col, int mat[][4])
{
    cout << "Printing matrix \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void printMatrixColumnWise(int row, int col, int mat[][4])
{
    cout << "Printing matrix \n";
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << mat[j][i] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

bool linearSearch(int mat[][4], int row, int col, int target)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (target == mat[i][j])
                return true;
        }
    }

    return false;
}

void rowWiseSum(int mat[][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += mat[i][j];
        }
        cout << sum << " ";
        sum = 0;
    }
    cout << endl;
}

void LargestSumRow(int mat[][4], int row, int col)
{
    int sum = 0;
    int maxi = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += mat[i][j];
        }
        // cout << sum << " ";
        maxi = max(maxi, sum);
        sum = 0;
    }
    cout << maxi << endl;
}

void colWiseSum(int mat[][4], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sum += mat[j][i];
        }
        cout << sum << " ";
        sum = 0;
    }
    cout << endl;
}

int main()
{

    int row, col;
    cout << "Enter rows and column respectively\n";
    cin >> row >> col;

    int mat[3][4];

    cout << "Enter the values in matrix\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }

    // printMatrixRowWise(row,col,mat);
    // printMatrixColumnWise(row,col,mat);

    // if(linearSearch(mat,row,col,7))cout<<"Found\n";
    // else cout<<"Not FOund!!!"<<endl;

    // rowWiseSum(mat, row, col);
    // colWiseSum(mat, row, col);

    LargestSumRow(mat,row,col);

    return 0;
}