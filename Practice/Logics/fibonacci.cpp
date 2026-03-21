#include <iostream>
using namespace std;

int fibIt(int n)
{

    int u = 0;
    int v = 1;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        ans = u + v;
        u = v;
        v = ans;
    }

    return v;
}

int fibRec(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibRec(n - 1) + fibRec(n - 2);
}

int main()
{

    int n = 5;

    int ans = fibRec(n);

    cout << ans << endl;

    return 0;
}