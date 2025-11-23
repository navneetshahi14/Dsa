#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr){
    unordered_map<int,int> mp;

    for(int i:arr){
        mp[i]++;

        if(mp[i] > 1) return i;
    }

    return -1;

}

int main() {

    vector<int> arr = {1,3,4,2,2};

    cout<<"The answer is "<<findDuplicate(arr)<<endl;
 
return 0;
}