#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallestElement(vector<int> &arr,int n){
    int size = arr.size();

    stack<int> st;
    st.push(-1);
    vector<int> ans;

    for(int i = size-1;i>=0;i--)
    {
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
}

int main() {


 
return 0;
}