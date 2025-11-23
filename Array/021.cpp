#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &arr){
    int n = arr.size();
    int maxPro = arr[0];
    int minPro = arr[0];
    int result = arr[0];

    for(int i = 1;i<n;i++){
        int curr = arr[i];

        if(curr < 0)
        {
            swap(minPro,maxPro);
        }

        maxPro = max(curr,curr*maxPro);
        minPro = min(curr,minPro*curr);

        result = max(result, maxPro);
    }

    return result;
}

int main() {
 
    vector<int> arr = {-2, 6, -3, -10, 0, 2};

    cout<<"The max product is "<<maxProduct(arr)<<endl;

return 0;
}