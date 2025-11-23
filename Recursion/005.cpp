#include <bits/stdc++.h>
using namespace std;

int countDistinctWayToClimbStair(long long nStair)
{
    if (nStair < 0)
        return 0;
    if (nStair == 0)
        return 1;

    return countDistinctWayToClimbStair(nStair - 1) + countDistinctWayToClimbStair(nStair - 2);
}

int main()
{

    int n;
    cin >> n;

    int ans = countDistinctWayToClimbStair(n);

    cout << ans << endl;

    return 0;
}