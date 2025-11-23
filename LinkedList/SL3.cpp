#include <bits/stdc++.h>
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

class SinglyLL
{
public:
    Node *head;

    SinglyLL()
    {
        head = nullptr;
    }

    void insertionAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void makeCircular(int data)
    {
        Node *temp = head;
        int count = 0;
        Node *newNode = new Node(data, head);
        while (temp->next != nullptr)
        {
            temp = temp->next;
            cout<<++count<<" ";
        }
        temp->next = newNode;
    }

    bool detectCircular(){

        if(head == nullptr || head->next == nullptr) return false;
        Node* slow = head;
        Node* fast = head->next;
        bool ans = false;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                ans = true;
                break;
            }
        }

        return ans;


    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }
};

int main()
{

    SinglyLL list;
    list.insertionAtEnd(1);
    list.insertionAtEnd(2);
    list.insertionAtEnd(3);
    list.insertionAtEnd(4);
    list.insertionAtEnd(5);
    list.insertionAtEnd(6);


    list.print();
    cout<<list.detectCircular()<<endl;
    list.makeCircular(7);
    cout<<endl;

    cout<<list.detectCircular()<<endl;

    return 0;
}