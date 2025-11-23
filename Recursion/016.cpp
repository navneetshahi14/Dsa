#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans,string output,int index,string str){
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }
    // exclude
    solve(ans,output,index+1,str);

    // include
    char element = str[index];
    output.push_back(element);

    solve(ans,output,index+1,str);
}

vector<string> subsequence(string str){
    vector<string> ans;
    string output = "";

    int index = 0;
    solve(ans,output,index,str);
    return ans;
}

int main() {

    string str = "str";

    vector<string> a = subsequence(str);

    for(string s:a){
        cout<<s<<endl;
    }
 
return 0;
}