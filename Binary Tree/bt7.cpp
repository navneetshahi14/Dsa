#include<bits/stdc++.h>
using namespace std;

class node{

    public: 
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class Solution{
    public:

    vector<int> inOrder(node* root)
    {
        vector<int> res;
        node* curr = root;

        while(curr != nullptr){
            if(curr->left == nullptr){
                res.push_back(curr->data);
                curr = curr->right;
            }else{
                node* prev = curr->left;
                while(prev->right != nullptr && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }else {
                    prev->right = nullptr;
                    res.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }

        return res;
    }

    void flatten(node* root){
        node* curr = root;

        while(curr != nullptr){
            
            if(curr->left){
                node* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }


};

int main() {
 
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);


    Solution sol;

    sol.flatten(root);
    vector<int> res = sol.inOrder(root);

    for(int i: res){
        cout<<i<<" ";
    }
    cout<<endl;

return 0;
}