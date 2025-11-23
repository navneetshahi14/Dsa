#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> result ;

    result.push_back(1);

    for(int i = 2;i<=n;i++)
    {
        int carry = 0;
        for(int j = 0;j<result.size();j++)
        {
            int prod = result[j]*i + carry;
            result[j] = prod%10;
            carry = prod/10;
        }

        while(carry)
        {
            result.push_back(carry%10);
            carry = carry/10;
        }
    }

    reverse(result.begin(),result.end());
    return result;
}

int main() {

    int n;
    cout<<"Enter the number \n";
    cin>> n;

    vector<int> ans = factorial(n);

    for(int i:ans)
    {
        cout<<i<<" ";
    }

    cout<<endl;
 
return 0;
}