#include<bits/stdc++.h>
using namespace std;

bool checkPal(string s,int low,int high)
{
    cout<<"Entering\n";

    if( s[low] != s[high] )
    {
        return false;
    }

    if(low > high){
        return true;
    }

    low = low + 1;
    high = high - 1;
    checkPal(s,low,high);
}

int main() {

    string s = "racecar";
    
    if(checkPal(s,0,s.length()-1)) cout<<"True\n";
    else cout<<"False\n";
 
return 0;
}