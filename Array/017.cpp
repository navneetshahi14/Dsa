#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int>& arr)
{
    vector<int> pos,neg;

    for(int i = 0;i<arr.size();i++){
        if(arr[i] < 0) neg.push_back(arr[i]);
        else pos.push_back(arr[i]);
    }

    int posIndex = 0,negIndex = 0;
    int i = 0;


    while(posIndex < pos.size() && negIndex < neg.size())
    {
        if(i % 2 == 0) arr[i++] = pos[posIndex++];
        else arr[i++] = neg[negIndex++];
    }

    while(posIndex < pos.size()){
        arr[i++] = pos[posIndex++];
    }

    while(negIndex < neg.size()) arr[i++] = neg[negIndex++];
}

int main() {

    vector<int> arr = {1, 2, 3, -4, -1, 4};
    rearrange(arr);
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";

    cout<<endl;
 
return 0;
}