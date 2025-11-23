#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
    if(b == 0){
        return 1;
    }

    b = b-1;

    return a * power(a,b);
}

int main() {

    cout<<"2 power 10 is "<<power(2,10)<<endl;
 
return 0;
}