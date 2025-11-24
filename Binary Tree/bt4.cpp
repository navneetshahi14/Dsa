#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


class Solution{



    public:

        void solve(node* root,int sum,int &maxSum,int len,int &maxlen)
        {
            if(root == NULL){
                if(len > maxlen){
                    maxlen = len;
                    maxSum = sum;
                }else if(len == maxlen){
                    maxSum = max(maxSum,sum);
                }
                return;
            }

            sum += root->data;

            solve(root->left,sum,maxSum,len,maxlen);
            solve(root->right,sum,maxSum,len,maxlen);

        }

        int sumOfLongRootToLeaf(node* root)
        {
            int len = 0;
            int maxlen = 0;

            int sum = 0;
            int maxSum = INT_MIN;

            solve(root,sum,maxSum,len,maxlen);
            return maxSum;
        }

        // Lowest common ancestor
        node* lca(node* root,int n1, int n2){
            if(root == NULL){
                return NULL;
            }

            if(root->data == n1 || root->data == n2){
                return root;
            }

            node* left = lca(root->left,n1,n2);
            node* right = lca(root->right,n1,n2);

            if(left != NULL && right != NULL){
                return root;
            }
            else if(left != NULL && right == NULL)
            {
                return left;
            }
            else if(left == NULL && right != NULL)
            {
                return right;
            }else {
                return NULL;
            }
        }

        void solveSumK(node* root,int k,int &count,vector<int> path){
            if(root == NULL) return ;

            path.push_back(root->data);

            solveSumK(root->left,k,count,path);
            solveSumK(root->right,k,count,path);

            int size = path.size();
            int sum = 0;
            for(int i = size-1;i >= 0;i--)
            {
                sum += path[i];
                if(sum == k){
                    count++;
                }
            }

            path.pop_back();
        }

        int sumK(node* root,int k){
            vector<int> path;
            int count = 0;
            solveSumK(root,k,count,path);
            return count;
        }

        node* ksolve(node* root,int &k,int nodes){
            if(root == NULL){
                return NULL;
            }

            if(root->data == nodes){
                return root;
            }

            node* left = ksolve(root->left,k,nodes);
            node* right = ksolve(root->right,k,nodes);

            if(left != NULL && right == NULL){
                k--;
                if(k<=0){
                    k = INT_MAX;
                    return root;
                }

                return left;
            }
        }

        int kthAncestor(node* root,int k,int nodes){
            node* ans = ksolve(root,k,nodes);

            if(ans == NULL) return -1;
            else return ans->data;
        }


        pair<int,int> GSolve(node* root){
            if(root== NULL){
                pair<int,int> p = make_pair(0,0);
                return p;
            }

            pair<int,int> left = GSolve(root->left);
            pair<int,int> right = GSolve(root->right);

            pair<int,int> res;

            res.first = root->data + left.second + right.second;

            res.second = max(left.first,left.second) + max(right.first,right.second);

            return res;             
        }

        int getMaxSum(node* root)
        {
            pair<int,int> ans = GSolve(root);

            return max(ans.first,ans.second);
        }
};


int main() {
 
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(1);
    root->left->right->left = new node(6);
    root->right->left = new node(2);
    root->right->right = new node(3);

    Solution sol;

    int ans = sol.sumOfLongRootToLeaf(root);
    cout<<"the answer is "<<ans<<endl;

    node* a = sol.lca(root,7,3);
    cout<<"the lca is "<<a->data<<endl;

    ans = sol.sumK(root,5);

    cout<<"the answer is "<<ans<<endl;

    ans = sol.kthAncestor(root,2,6);
    cout<<"the answer is "<<ans<<endl;

    ans = sol.getMaxSum(root);
    cout<<"the answer is "<<ans<<endl;

return 0;
} 