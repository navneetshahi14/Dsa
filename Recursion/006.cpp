#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int size){
    if(size == 1 || size == 0){
        return true;
    }

    if(arr[0]>arr[1]) return false;
    else return isSorted(arr+1, size-1);
}

int main() {

    int arr[5] =  {4,6,9,7};

    if(isSorted(arr,5)){cout<<"True\n";}
    else cout<<"False \n";
 
return 0;
}