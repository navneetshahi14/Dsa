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

// Height of a binary tree
int height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<int,int> diameterFast(node* root){
    if(root == nullptr)
    {
        pair<int,int> p = make_pair(0,0);
        return p;   
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans ;

    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;
}

int diameter (node* root){
    // if(root == nullptr){
    //     return 0;
    // }

    // int op1 = diameter(root->left);
    // int op2 = diameter(root->right);
    // int op3 = height(root->left) + height(root->right) + 1;

    // int ans = max(op1,max(op2,op3));
    // return ans;

    return diameterFast(root).first;
}

bool isBalanced (node* root)
{
    if(root == nullptr){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff){
        return true;
    }
    else {
        return false;
    }
    
}

int main()
{

    node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(7);
    root->left->right = new node(11);
    root->right = new node(5);
    root->right->left = new node(17);

    int ans = height(root);
    cout << "The height is " << ans << endl;
    ans = diameter(root);
    cout<<"The diameter is "<<ans<<endl;

    if(isBalanced(root)){
        cout<<"it is balanced"<<endl;
    }else {
        cout<<"it is not balanced"<<endl;
    }

    return 0;
}