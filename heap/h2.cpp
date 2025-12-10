#include<bits/stdc++.h>
using namespace std;

int kthSmallestElem(int arr[],int l,int e,int k){
    priority_queue<int> pq;

    for(int i = 0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i = k;i<e;i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main() {

    int arr[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;

    int ans = kthSmallestElem(arr,0,6,k);
    cout<<"the answer is "<<ans;
return 0;
}