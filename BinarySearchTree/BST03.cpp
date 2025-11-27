#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            left = right = nullptr;
        }
};

class Solution{
    private:

    public:
        void inorder(node* root,vector<int> &in){
            if(root == nullptr) return ;

            inorder(root->left,in);
            in.push_back(root->data);
            inorder(root->right,in);
        }

        void inorder2(node* root,vector<node*> &ine)
        {
            if(root == nullptr) return ;

            inorder2(root->left,ine);
            ine.push_back(root);
            inorder2(root->right,ine);
        }
        // Two sum in BST
        pair<int,int> TwoSum(node* root,int target){
            vector<int> in;

            inorder(root,in);

            int n = in.size();

            int i = 0,j = n-1;

            while(i < j){
                int elem1 = target - in[i];
                int elem2 = in[j];

                if(elem1 == elem2){
                    pair<int,int> p = make_pair(in[i],in[j]);
                    return p;
                }else if(elem1 > elem2){
                    i++;
                }else{
                    j--;
                }
            }

            return {-1,-1};
        }


        // Flatten BST to Sorted list
        void flatten(node* root){
            vector<node*> ine;
            inorder2(root,ine);

            int n = ine.size();

            for(int i = 0;i<n-1;i++){
                ine[i]->right = ine[i+1];
                ine[i]->left = nullptr;
            }

        }

        // Normal BST to Balanced BST
        node* buildBalanceBST(vector<int> &in,int start,int end){
            if(start > end) return nullptr;

            int mid = (start + end)/2;
            node* root = new node(in[mid]);

            root->left = buildBalanceBST(in,start,mid-1);
            root->right = buildBalanceBST(in,mid+1,end);
        }

        node* balanceBSt(node* root){
            vector<int> in;
            inorder(root,in);

            return buildBalanceBST(in,0,in.size()-1);
        }

        void inOrder(node* root){
            if(root == nullptr)return ;

            inOrder(root->left);
            cout<<root->data<<" ";
            inOrder(root->right);
        }

        // BSTfromPreorder

        node* solve(vector<int> &preorder,int mini,int maxi,int &i){
            if(i >= preorder.size()){
                return nullptr;
            }

            if(preorder[i] < mini || preorder[i] > maxi){
                return nullptr;
            }

            node* root = new node(preorder[i++]);

            root->left = solve(preorder,mini,root->data,i);
            root->right = solve(preorder,root->data,mini,i);
            return root;
        }

        node* preorderToBST(vector<int> *preorder){
            int mini = INT_MIN;
            int maxi = INT_MAX;

            return solve(preorder,mini,maxi,0);
        }
};

int main() {
 
    node* root = new node(7);
    root->left = new node(3);
    root->right = new node(8);

    root->left->right = new node(4);
    root->left->left = new node(2);

    root->right->right = new node(9);

    Solution sol;

    pair<int,int> p = sol.TwoSum(root,5);

    cout<<"The numbers are "<<p.first<<", "<<p.second<<endl;

    sol.flatten(root);

    node* root2 = new node(30);
    root2->left = new node(20);
    root2->left->left = new node(10);

    node* root3 = sol.balanceBSt(root2);
    sol.inOrder(root3);


return 0;
}