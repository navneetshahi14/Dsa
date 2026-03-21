#include <iostream>
using namespace std;

int gcdRec(int a, int b)
{
    if (b == 0)
        return a;

    return gcdRec(b, a % b);
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

int main()
{

    return 0;
}