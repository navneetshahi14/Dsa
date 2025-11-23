#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = nullptr;
        }

        Node(int data,Node* next){
            this->data = data;
            this->next = next;
        }
};

class SinglyLL{
    public:
        Node* head;

        SinglyLL(){
            head = nullptr;
        }

        void insertionAtend(int data){
            Node* newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }

            temp->next = newNode;
        }

        // Remove duplicates from sorted LL
        void removeDupFromSorted()
        {
            Node* i = head;
            Node* j = head->next;

            while(j != nullptr){
                if(i->data == j->data){
                    while( j != nullptr && i->data == j->data ){
                        j = j->next;
                    }
                    i->next = j;
                }
                i = i->next;
                if(j != nullptr){
                    j = j->next;
                }
            }
        }
        

        void printLL(){
            Node* temp = head;
            while(temp!= nullptr){
                cout<<temp->data<<" --> ";
                temp = temp->next;
            }

            cout<<"NULL"<<endl;
        }

        ~SinglyLL(){
            delete head;
        }
};

int main() {
    SinglyLL list;
    list.insertionAtend(1);
    list.insertionAtend(2);
    list.insertionAtend(2);
    list.insertionAtend(2);
    list.insertionAtend(3);
    list.insertionAtend(3);
    list.insertionAtend(4);
    list.insertionAtend(5);
    list.insertionAtend(5);

 
    list.printLL();
    list.removeDupFromSorted();
    list.printLL();
return 0;
}