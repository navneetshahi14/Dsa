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
};

void reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }


    head = prev;
}

class SinglyLL
{

public:
    Node *head;

    SinglyLL()
    {
        head = nullptr;
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }


    bool checkpalindrome(){
        Node* slow = head;
        Node* fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        fast = slow->next;
        slow = head;
        reverseLL(fast);
        while(slow != nullptr && fast != nullptr){
            if(slow->data != fast->data) return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
        
    }

     void printLL()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    ~SinglyLL()
    {
        delete head;
    }
};



int main()
{
    SinglyLL list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    if(list.checkpalindrome()){
        cout<<"True"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    return 0;
}