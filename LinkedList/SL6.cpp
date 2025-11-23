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
    SinglyLL(){
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

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
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

Node *Merging(Node *list1, Node *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Node *head = nullptr;
    Node *tail = nullptr;

    while (list1 != nullptr && list2 != nullptr)
    {
        Node *newNode;
        if (list1->data < list2->data)
        {
            newNode = new Node(list1->data);
            list1 = list1->next;
        }
        else if (list1->data > list2->data)
        {
            newNode = new Node(list2->data);
            list2 = list2->next;
        }
        else
        {
            newNode = new Node(list1->data);
            list1 = list1->next;
            list2 = list2->next;
        }

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    while (list1 != nullptr)
    {
        Node *newNode = new Node(list1->data);
        tail->next = newNode;
        tail = tail->next;
        list1 = list1->next;
    }

    while (list2 != nullptr)
    {
        Node *newNode = new Node(list2->data);
        tail->next = newNode;
        tail = tail->next;
        list2 = list2->next;
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL " << endl;
}

int main()
{

    SinglyLL list1;
    SinglyLL list2;

    list1.insertAtEnd(1);
    list1.insertAtEnd(3);
    list1.insertAtEnd(5);
    list1.insertAtEnd(7);
    list2.insertAtEnd(2);
    list2.insertAtEnd(4);
    list2.insertAtEnd(6);
    list2.insertAtEnd(8);
    list1.printLL();
    list2.printLL();

    Node *head = Merging(list1.head, list2.head);

    print(head);

    return 0;
}