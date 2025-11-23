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
private:
    Node *reverseLL(Node *head)
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *next = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

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

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtEnd(int data, Node *head2)
    {
        Node *newNode = new Node(data);
        if (head2 == nullptr)
        {
            head2 = newNode;
            return;
        }

        Node *temp = head2;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    Node *add(Node *l1, Node *l2)
    {

        int carry = 0;
        Node *ansHead = nullptr;
        Node *ansTail = nullptr;

        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = carry + l1->data + l2->data;
            int dig = sum % 10;

            insertAtEnd(dig, ansHead);

            carry = sum / 10;
        }

        while (l1 != nullptr)
        {
            int sum = carry + l1->data;
            int dig = sum%10;

            insertAtEnd(dig, ansHead);
            carry = sum/10;
        }

        while(l2 != nullptr)
        {
            int sum = carry + l2->data;
            int dig = sum%10;

            insertAtEnd(dig,ansHead);
            carry = sum/10;
        }

        while(carry != 0)
        {
            int sum = carry;
            int dig = sum % 10;
            insertAtEnd(dig,ansHead);
            carry  =sum/10; 
        }

        return ansHead;
    }

    Node *addLL(Node *l1, Node *l2)
    {

        Node *ans;

        l1 = reverse(l1);
        l2 = reverse(l2);

        ans = add(l1, l2);

        ans = reverse(ans);

        return ans;
    }

    void printLL()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    ~SinglyLL()
    {
        delete head;
    }
};

int main()
{

    return 0;
}