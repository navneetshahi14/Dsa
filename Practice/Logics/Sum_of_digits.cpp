#include <iostream>
using namespace std;

int sumdig(int n)
{
    int sum = 0;

    while (n)
    {
        int temp = n % 10;
        sum += temp;
        n /= 10;
    }

    return sum;
}

int main()
{

    int n = 12345;

    cout << sumdig(n) << endl;

    return 0;
}