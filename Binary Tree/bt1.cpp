#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *leftchild;
    Node *rightchild;

    Node(int data)
    {
        this->data = data;
        this->leftchild = nullptr;
        this->rightchild = nullptr;
    }
};

Node *buildTree(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "Enter data for inserting at left " << data << endl;
    root->leftchild = buildTree(root->leftchild);
    cout << "Enter data for inserting at right " << data << endl;
    root->rightchild = buildTree(root->rightchild);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->leftchild){
            q.push(temp->leftchild);
        }

        if(temp->rightchild){
            q.push(temp->rightchild);
        }
    }
    cout<<endl;
}

void inorderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    inorderTraversal(root->leftchild);
    cout<<root->data<<" ";
    inorderTraversal(root->rightchild);
}

void preorderTraversal(Node* root){
    if(root == nullptr) {
        return;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->leftchild);
    preorderTraversal(root->rightchild);
}

void postOrderTraversal(Node* root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->leftchild);
    postOrderTraversal(root->rightchild);
    cout<<root->data<<" ";
}

int main()
{

    Node *root = nullptr;

    // create tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // levelOrderTraversal
    levelOrderTraversal(root);
    // inorder traversal
    inorderTraversal(root);
    cout<<endl;
    // preorder traversal
    preorderTraversal(root);
    cout<<endl;
    // postorder traversal
    postOrderTraversal(root);

    return 0;
}