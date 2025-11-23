#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSorted(vector<int> &a,vector<int> &b){
    int i = 0;
    int j = 0;

    int n = a.size()-1;
    int m = b.size()-1;
    vector<int> ans;

    while(i <= n && j <= m)
    {
        if(a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
        }else if(a[i] > b[j]){
            ans.push_back(b[j]);
            j++;
        }else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    while(i<=n){
        ans.push_back(a[i]);
        i++;
    }

    while(j<=m){
        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

int main() {
 
    vector<int> a = {1,3,5,7};
    vector<int> b = {2,4,6,8};

    vector<int> ans = mergeSorted(a,b);

    for(int i:ans){
        cout<<i<<" ";
    }

    cout<<endl;

return 0;
}