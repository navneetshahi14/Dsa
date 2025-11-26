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

        node* createParentMapping(node* root,int target, map<node*,node*> &nodeToParent){
            node* res = nullptr;

            queue<node*> q;
            q.push(root);

            nodeToParent[root] = nullptr;

            while(!q.empty()){
                node* front = q.front();
                q.pop();

                if(front->data == target){
                    res = front;
                } 

                if(front->left){
                    nodeToParent[front->left] = front;
                    q.push(front->left); 
                }

                if(front->right){
                    nodeToParent[front->right] = front;
                    q.push(front->right);
                }
            }

            return res;
        }

        int burnTree(node* root,map<node*, node*> &nodeToParent){

            map<node*,bool> visited;
            queue<node*> q;
            q.push(root);

            visited[root] = 1;

            int ans = 0;

            while(!q.empty()){
                bool flag = 0;
                int size = q.size();
                for(int i = 0;i<size;i++){
                    node* front = q.front();
                    q.pop();

                    if(front->left && !visited[front->left]){
                        flag = 1;
                        q.push(front->left);
                        visited[front->left] = 1;
                    }

                    if(front->right && !visited[front->right]){
                        flag = 1;
                        q.push(front->right);
                        visited[front->right] = 1;
                    }

                    if(nodeToParent[front] && !visited[nodeToParent[front]]){
                        flag = 1;
                        q.push(nodeToParent[front]);
                        visited[nodeToParent[front]] = 1;
                    }


                }

                if(flag == 1){
                    ans++;
                }
            }

            return ans;

        }

        int minTime(node* root,int target)
        {
            map<node*, node*> nodeToParent;
            node* targetNode = createParentMapping(root,target,nodeToParent);

            int ans = burnTree(targetNode,nodeToParent);
            return ans;
        }
};

int main() {

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);

    root->right->right = new node(6);
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(10);

    Solution sol;

    int ans = sol.minTime(root,8);
    cout<<"The answer is "<<ans<<endl;
 
return 0;
}