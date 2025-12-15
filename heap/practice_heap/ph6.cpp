#include<bits/stdc++.h>
using namespace std;

int height(int n){
    return floor(log2(n));
}

int main() {
 
    int N;
    cout<<"Enter N"<<endl;
    cin>>N;
    cout<<height(N)<<endl;

return 0;
}