#include<bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{

    if(str.length() == 1) return -1;
    stack<char> st;

    for(int i = 0;i<str.length();i++){
        char elem = str[i];
       
        if(elem == '('){
            st.push(elem);
        }
        else{
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else{
                st.push(elem);
            }
        }

        
    }
    int a = 0,b = 0;
    while(!st.empty()){
        if(st.top() == '('){
            b++;
        }else{
            a++;
        }
        st.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main() {
 
    string str = "(()())";
    int a = findMinimumCost(str);

    cout<<"The answer is "<<a<<endl;

return 0;
}