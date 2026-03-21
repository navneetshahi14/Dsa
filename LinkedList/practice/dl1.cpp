#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = this->prev = nullptr;
    }
};

class Solution{
    public:
    Node* head;

    Solution(){
        head = nullptr;
    }

    
};

int main()
{

    return 0;
}