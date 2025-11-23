#include<bits/stdc++.h>
using namespace std;

void revers(string& s,int low, int high)
{
    if(low > high) return;

    swap(s[low++],s[high--]);
    revers(s,low,high);
}

int main() {

    string s = "navneet";
    revers(s,0,s.length()-1);

    cout<<s<<endl;
 
return 0;
}