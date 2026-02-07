#include<iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {64,25,12,22,11};

    for(int i = 0;i<arr.size();i++)
    {
        int current = i;

        int mini = i;

        for(int j = i;j<arr.size();j++){
            if(arr[mini] > arr[j]){
                mini = j;
            }
        }

        if(mini != arr[i])
        {
            swap(arr[current],arr[mini]);
        }
    }

    for(int i :arr){
        cout<<i<<" ";
    }

    cout<<endl;


    return 0;
}