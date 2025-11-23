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

class LinkedList
{
public:
    Node *head;

    LinkedList()
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

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Reverse LinkedList
    void reverseLL (){
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while(current != nullptr){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    // middle Element
    int middleElement(){
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data;
    }

    // Print LinkedList
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
};

int main()
{

    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    list.printLL();
    list.reverseLL();
    list.printLL();

    cout<<"The middle element is "<<list.middleElement()<<endl;

    return 0;
}