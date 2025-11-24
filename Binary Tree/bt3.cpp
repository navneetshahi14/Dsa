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

void zigzagTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    bool reversed = true;

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (reversed)
        {
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }

            reversed = false;
        }

        else
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }

            reversed = true;
        }
    }
}

void traversalLeft(node *root, vector<int> &ans)
{

    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        traversalLeft(root->left, ans);
    }
    else
    {
        traversalLeft(root->right, ans);
    }
}

void traversalLeaf(node *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
        return;
    }

    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

void traversalRight(node *root, vector<int> &ans)
{
    if ((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    {
        return;
    }

    if (root->right)
    {
        traversalRight(root->right, ans);
    }
    else
    {
        traversalRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    ans.push_back(root->data);

    traversalLeft(root->left, ans);
    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);

    traversalRight(root->right, ans);

    return ans;
}

vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int>>> nodes;

    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == nullptr)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

vector<int> bottomView(node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }

    map<int, int> nodes;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second;

        nodes[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : nodes)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{

    node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right = new node(11);
    root->right = new node(5);
    root->right->left = new node(17);
    root->right->right = new node(18);
    root->right->right->left = new node(20);
    root->right->right->right = new node(21);

    zigzagTraversal(root);
    cout << endl;

    vector<int> ans = boundaryTraversal(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    ans = verticalOrder(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    ans = topView(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    ans = bottomView(root);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}