#include<bits/stdc++.h>
using namespace std;

void solve(vector<string> &ans,string output,int index,string *mapping, string str){
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }

    // exclude
    // solve(ans,output,index+1,mapping,str);

    // include
    int number = str[index] - '0';
    string value = mapping[number];

    for(int i = 0;i<value.length();i++){
        output.push_back(value[i]);
        solve(ans,output,index+1,mapping,str);
        output.pop_back();
    }
}

vector<string> letterCombinations(string str){
    vector<string> ans;
    if(str.length() == 0) return ans;
    string output = "";
    int index = 0;

    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(ans,output,index,mapping,str);

    return ans;
}

int main() {

    string digit = "23";

    vector<string> ans = letterCombinations(digit);

    cout<<"{ ";
    for(auto s:ans){
        cout<<s<<" , ";
    }

    cout<<"}\n";
 
return 0;
}