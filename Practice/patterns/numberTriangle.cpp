#include <iostream>
using namespace std;

void printnumber(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void FloydTriangle(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void tri01(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void invertedDiamond(int n)
{

    // Upper part
    for (int i = 1; i <= n; i++)
    {

        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "    ";
        }

        // stars
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    // Lower part
    for (int i = 1; i < n; i++)
    {

        // spaces
        for (int j = 1; j <= i; j++)
        {
            cout << "  ";
        }

        // stars
        for (int j = 1; j <= (2 * (n - i) - 1); j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}

int main()
{

    invertedDiamond(5);

    return 0;
}