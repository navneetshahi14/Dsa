#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    int findPostion(vector<int> in, int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    node *solve(vector<int> in, vector<int> pre, int &preIndex, int start, int end, int n)
    {
        if (preIndex >= n || start > end)
        {
            return nullptr;
        }

        int elem = pre[preIndex++];

        node *temp = new node(elem);

        int position = findPostion(in, elem,n);

        temp->left = solve(in,pre,preIndex,start,position-1,n);
        temp->right = solve(in,pre,preIndex,position+1,end,n);

        return temp;
    }

    node *buildTree(vector<int> InO, vector<int> PreO)
    {
        int n = InO.size();

        int preOrderIndex = 0;
        node *ans = solve(InO, PreO, preOrderIndex, 0, n - 1, n);

        return ans;
    }


    void postOrder(node* root)
    {
        if(root == nullptr){
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
};

int main()
{

    vector<int> in = {3,1,4,0,5,2};
    vector<int> po = {0,1,3,4,2,5};

    Solution sol;
    node* root = sol.buildTree(in,po);

    sol.postOrder(root);
    cout<<endl;

    return 0;
}