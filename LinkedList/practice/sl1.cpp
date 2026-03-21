#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Solution
{
public:
    Node *head;

    Solution(){
        head = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    void deleteLastNode(){
        Node* temp = head;

        while(temp->next->next != nullptr){
            temp = temp->next;
        }

        temp->next = nullptr;
    }

    void lengthOfLL(){
        int i = 0;
        Node* temp = head;
        
        while(temp != nullptr){
            temp = temp->next;
            i++;
        }

        cout<<i<<endl;
    }

    void findPointer(int k){
        Node* temp = head;
        bool found = false;

        while(temp != nullptr){
            if(temp->data == k){
                found = true;
                cout<<"found"<<endl;
                break;
            }else{
                temp = temp->next;
            }
        }

        if(!found) cout<<"Not found"<<endl;
    }

    void printlist()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    Node *y = new Node(arr[0]);

    cout << y << endl;
    cout << y->data << endl;

    Node *z = new Node(arr[1], y);

    cout << z->next->data << endl;

    Solution sol;

    sol.insertAtHead(2);
    sol.insertAtHead(1);
    sol.insertAtHead(0);
    sol.insertAtHead(5);

    sol.printlist();
    sol.lengthOfLL();

    sol.deleteLastNode();
    sol.printlist();

    sol.lengthOfLL();

    sol.findPointer(6);

    return 0;
}