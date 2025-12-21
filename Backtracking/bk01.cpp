#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx,int newy,vector<vector<bool>> &vis, vector<vector<int>> &arr,int n){
    if((newx >=0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] != 1 && arr[newx][newy] == 1){
        return true;
    }else {
        return false;
    }
}

void solve(int x,int y, vector<string> &ans,vector<vector<int>> &arr,int n, vector<vector<bool>> &vis,string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    
    vis[x][y] = 1;

    // 4 movements
    // D, L , R, U

    // Down
    if(isSafe(x+1,y,vis,arr,n)){
        solve(x+1,y,ans,arr,n,vis,path + 'D');
    }

    // Left
    if(isSafe(x,y-1,vis,arr,n)){
        solve(x,y-1,ans,arr,n,vis,path + 'L');
    }

    // Right
    if(isSafe(x,y+1,vis,arr,n)){
        solve(x,y+1,ans,arr,n,vis,path + 'R');
    }

    // Upward
    if(isSafe(x-1,y,vis,arr,n)){
        solve(x-1,y,ans,arr,n,vis,path + 'U');
    }

    vis[x][y] = 0;
}

vector<string> searchMatrix(vector<vector<int>> &arr,int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n,0));
    string path;
    if(arr[0][0] == 0){
        return ans;
    }

    solve(0,0,ans,arr,n,visited,path);

    return ans;
}

int main() {

    vector<vector<int>> arr = {{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};

    vector<string> ans = searchMatrix(arr,4);

    for(int i = 0;i< ans.size();i++){
        cout<<ans[i]<<endl;
    }
 
return 0;
}