#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q){
    stack<int> st;

    while(!q.empty()){
        int elem = q.front();
        q.pop();
        st.push(elem);
    }

    while(!st.empty()){
        int top = st.top();
        st.pop();
        q.push(top);
    }

    return q;
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
}

int main() {
 
    queue<int> q;

    for(int i = 1;i<=5;i++){
        q.push(i);
    }

    print(q);

    q = rev(q);

    print(q);

return 0;
}