#include<bits/stdc++.h>
using namespace std;

pair<int,int> maxMin(vector<int> arr){
    int min = INT_MAX;
    int max = INT_MIN;

    int n = arr.size();

    for(int i = 0;i<n;i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }

        if(arr[i] < min){
            min = arr[i];
        }
    }

    pair<int,int> p = make_pair(max,min);

    return p;
}

int main() {

    vector<int> arr = {2,3,4,5,10,6,7,8,1};

    pair<int,int> p1 = maxMin(arr);

    cout<<"The maximum element is "<<p1.first<<endl;
    cout<<"The minimum element is "<<p1.second<<endl;
 
return 0;
}