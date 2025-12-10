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

int countNode(node* root){
    if(root == nullptr){
        return 0;
    }

    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}

bool isCBT(node* root,int index,int totalCount){
    if(root == nullptr) return true;

    if(index >= totalCount){
        return false;
    }
    else{
        bool left = isCBT(root->left,2*index+1,totalCount);
        bool right = isCBT(root->right,2*index+2,totalCount);

        return (left && right);
    }

}

bool isMaxOrder(node* root){
    // leaf node
    if(root->left == nullptr && root->right == nullptr) return true;

    if(root->right == nullptr){
        return (root->data > root->left->data);
    }else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right &&( root->data > root->left->data && root->data > root->right->data));
    }
}

bool isHeap(node* root){
    int index = 0;
    int totalCount = countNode(root);
    
    if(isCBT(root,index,totalCount) && isMaxOrder(root)){
        return true; 
    }
}

int main() {
 
return 0;
}