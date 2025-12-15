#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && arr[smallest] > arr[l]){
        smallest = l;
    }

    if(r<n && arr[smallest] > arr[r]){
        smallest = r;
    }

    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}

void heapSort(int arr[],int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for( int i = n-1;i >= 0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}

void printArray(int arr[],int n){
    for(int i = 0;i<n;++i){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
}

int main() {

    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
 
return 0;
}