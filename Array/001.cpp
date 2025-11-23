#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr)
{

    int s = 0;
    int e = arr.size() -1;
    while(s <= e)
    {
        swap(arr[s++],arr[e--]);
    }
}

void printArray(vector<int> arr){
    for(int i = 0; i < arr.size(); i++ )
    {
        cout<< arr[i] <<" ";
    }
    cout<<"\n";
}

int main() {

    vector<int> arr = {1,2,3,4,5,6,7};
    printArray(arr);
    reverseArray(arr);
    printArray(arr);



    return 0;
}