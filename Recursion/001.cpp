#include<bits/stdc++.h>
using namespace std;

int factorical(int n){

    // base case
    if(n == 1){
        return 1;
    }

    return n * factorical(n-1);
}

int main() {
 
    int n ;
    cin>> n;

    int ans = factorical(n);

    cout<<"The factorial of "<<n<<" is "<<ans<<endl;

return 0;
}