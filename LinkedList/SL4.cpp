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

class SinglyLL {
    public:
        Node* head;

        SinglyLL(){
            head = nullptr;
        }

        void insertAtend(int data){
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


        bool DetectLoop(){

            if(head == nullptr || head->next == nullptr) return false;
            Node* slowptr = head;
            Node* fastptr = head->next;
            int count = 1;
            while(fastptr != nullptr && fastptr->next != nullptr){
                slowptr = slowptr->next;
                fastptr = fastptr->next->next;

                if(slowptr == fastptr){
                    cout<<endl;
                    return true;
                }

                cout<<count++<<" ";
            }

            cout<<endl;

            return false;
        }

        void makeCircular(int data,int k){
            Node* ptr = head;
            for(int i =0;i<k;i++){
                ptr = ptr->next;
            }
            cout<< "pointing to :-> " <<ptr->data<<"\n";

            Node* newNode = new Node(data,ptr);
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }

            temp->next = newNode;
            cout<<"Created Circular linkedList"<<endl;
        }

        Node* startingNode(){
            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr  && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast ) break;
            }
            cout<<"slow is :-> "<<slow->data<<endl;
            cout<<"fast is :-> "<<fast->data<<endl;

            if(fast == nullptr && fast->next == nullptr) return nullptr;

            slow = head ;
            while(fast != slow){
                slow = slow->next;
                fast = fast->next;

                cout<<"slow :-> "<<slow->data<<" , fast :-> "<<fast->data<<endl;
            }

            return slow;
            
        }

        void removingLoop(){
            Node* slow = head;
            Node* fast = head;
            Node* prev = nullptr;

            while(fast != nullptr && fast->next != nullptr){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) break;
            }

            prev->next = nullptr;
        }

        void printLL(){
            Node* temp = head;
            while(temp != nullptr){
                cout<<temp->data<<" --> ";
                temp = temp->next;
            }
            cout<<"Null"<<endl;
        }

        ~SinglyLL(){
            delete head;
        }
};

int main() {

    SinglyLL list;
    list.insertAtend(1);
    list.insertAtend(2);
    list.insertAtend(3);
    list.insertAtend(4);
    list.insertAtend(5);
    list.insertAtend(6);
    list.insertAtend(7);


    cout<<list.DetectLoop()<<endl;
    list.printLL();
    list.makeCircular(8,2);
    cout<<list.DetectLoop()<<endl;
 
    if(list.DetectLoop()){
        Node* head = list.startingNode();
        cout<<"Loop starting at Node "<<head->data<<endl;
    }else{
        cout<<"No Loop detected\n";
    }

    list.removingLoop();
    if(list.DetectLoop()){
        cout<<"Loop detected"<<endl;
    }else {
        cout<<"No Loop"<<endl;
    }

return 0;
}