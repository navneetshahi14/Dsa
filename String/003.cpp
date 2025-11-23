#include<bits/stdc++.h>
using namespace std;

void printDuplicates(string& s){
    unordered_map<char,int> freq;

    for(char c:s){
        freq[c]++;
    }

    for(auto it : freq)
    {
        if(it.second > 1){
            cout<<"[ '"<<it.first<<"', "<<it.second<<"], ";
        }
    }

    cout<<endl;
}

int main() {

    string s = "geeksforgeeks";

    printDuplicates(s);

 
return 0;
}