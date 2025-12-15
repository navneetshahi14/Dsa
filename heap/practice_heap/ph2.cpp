#include<bits/stdc++.h>
using namespace std;

bool isHeap(int arr[],int n,int i){
    if( i > (n-1)/2){
        return true;
    }

    if(arr[i] >= arr[2*i+1] && arr[i] >= arr[2*i+2] && isHeap(arr,n, 2*i+1) && isHeap(arr,n,2*i+2)){
        return true;
    }

    return false;

}

int main() {
 
    int arr[] = { 90, 15, 10, 7, 12, 2, 7, 3 };

    int n = sizeof(arr)/sizeof(int)-1;

    isHeap(arr,n,0) ? cout<<"Yess"<<endl : cout<<"Noo"<<endl;

return 0;
}