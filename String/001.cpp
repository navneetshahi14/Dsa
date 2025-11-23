#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<char> s = {'h','e','l','l','o'};

    int n = s.size();

    int left = 0, right = n-1;

    while(left <= right)
    {
        swap(s[left++],s[right--]);
    }

    for(char i:s){
        cout<<i<<" ";
    }
    cout<<endl;
 
return 0;
}