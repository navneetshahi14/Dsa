#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = this->right = nullptr; 
        }
};

bool isBST(node* root){
    static node* prev = nullptr;
    if(root != nullptr){
        if(!isBST(root->left)){
            return false;
        }
        if(prev != nullptr && root->data <= prev->data){
            return false;
        }
        prev = root;
        return isBST(root->right);
    }else{
        return true;
    }
}

int solve(node* root,int &i,int tar){
    if(root == nullptr) return -1;

    int left = solve(root->left,i,tar);
    if(left != -1){
        return left;
    }

    i++;

    if(i == tar) return root->data;

    return solve(root->right,i,tar);
}

int kSmallest(node* root,int tar){
    int i = 0;
    int ans = solve(root,i,tar);
    return ans;
}

int main() {
 
    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(8);
    root->left->left = new node(2);
    root->left->left->right = new node(3);
    root->right->left = new node(6);
    root->right->left->right = new node(7);
    root->right->right = new node(10);

    if(isBST(root)){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;

    int ans = kSmallest(root,3);
    cout<<ans<<endl;


return 0;
}