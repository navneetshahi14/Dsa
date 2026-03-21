#include <iostream>
using namespace std;

bool palindrome(int n)
{
    if (n < 0)
        return false;

    if (n % 10 == 0 && n != 0)
        return false;

    int rev = 0;

    while (n > 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    return (n == rev) || (n == rev / 10);
}

int reverseNumber(int n)
{
    if (n == 0)
        return 0;

    int rev = 0;
    while (n > 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    return rev;
}

int main()
{

    int n = 1231;

    if (palindrome(n))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    cout << reverseNumber(12345) << endl;

    return 0;
}