#include <iostream>
using namespace std;

void invertedRight(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " *";
        }
        cout << endl;
    }
}

void invertedLeft(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << " *";
        }
        cout << endl;
    }
}

int main()
{

    invertedLeft(5);

    return 0;
}