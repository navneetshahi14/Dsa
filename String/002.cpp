#include<bits/stdc++.h>
using namespace std;

int main() {

    string s = "abbab";

    int left = 0;

    int right = s.size()-1;

    while(left <= right ){
        if(s[left] != s[right]){
            cout<<"False"<<endl;
            break;
        }

        left++;
        right--;

    }

    cout<<"True"<<endl;
 
return 0;
}