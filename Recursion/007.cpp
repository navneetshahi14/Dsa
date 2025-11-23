#include<bits/stdc++.h>
using namespace std;

int sumall(int *arr,int n){
    if(n == 0){
        return arr[0];
    }

    return arr[n] + sumall(arr,n-1);
}

int main() {
 
    int arr[] = {3,2,5,1,6};
    int n = 4;

    int ans = sumall(arr,n);

    cout<<ans<<endl;

return 0;
}