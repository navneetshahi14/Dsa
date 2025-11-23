#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int *arr,int low, int high,int target){

    if(low > high){
        return false;
    }
    int mid = low + (high - low )/2;

    if(arr[mid] == target){
        return true;
    }else if(arr[mid] > target){
        return binarySearch(arr,low, mid-1,target);
    }else {
        return binarySearch(arr,mid+1,high,target);
    }
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;

    if(binarySearch(arr,0,n-1,10)) cout<<"True\n";
    else cout<<"False\n";
 
return 0;
}