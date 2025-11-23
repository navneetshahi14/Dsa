#include<bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &a,vector<int> &b)
{
    unordered_map<int,int> mp;

    int n = a.size();
    int m = b.size();

    for(int i = 0;i<n;i++)
    {
        mp[a[i]]++;
    }

    for(int i = 0;i<m;i++){
        if(mp[b[i]] == 0) return false;
        mp[b[i]]--;
    }

    return true;
}

int main() {

    vector<int> a= {11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> b= {11, 3, 7, 1, 7};

    if(isSubset(a,b))cout<<"True"<<endl;
    else cout<<"False"<<endl;
 
return 0;
}