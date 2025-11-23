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

class SinglyLL
{
public:
    Node *head;

    SinglyLL()
    {
        head = nullptr;
    }

    void InsertAtEnd(int data)
    {
        if (head == nullptr)
        {
            head = new Node(data);
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = new Node(data);
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node *ReverseKGroup(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    Node *next = nullptr;
    Node *curr = head;
    Node *prev = nullptr;

    int count = 0;

    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr)
    {
        head->next = ReverseKGroup(next, k);
    }

    return prev;
}



void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    SinglyLL list;
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.InsertAtEnd(4);
    list.InsertAtEnd(5);
    list.InsertAtEnd(6);

    list.print();

    Node* head = ReverseKGroup(list.head, 2);
    printLL(head);

    return 0;
}