#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int *arr,int n, int target){
    if(arr[n] == target) return true;
    if(n < 0) return false;

    return linearSearch(arr,n-1,target);
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9};

    if(linearSearch(arr,8,10)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
 
return 0;
}