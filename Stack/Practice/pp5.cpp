#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
};

class LinkedListQueue
{
private:
    Node *start;
    Node *end;
    int size;

public:
    LinkedListQueue()
    {
        start = end = nullptr;
        size = 0;
    }

    void push(int x)
    {
        Node *element = new Node(x);
        if (start == nullptr)
        {
            start = end = element;
        }
        else
        {
            end->next = element;
            end = element;
        }

        size++;
    }

    int pop()
    {
        if (start == nullptr)
        {
            return -1;
        }

        int val = start->val;
        Node *temp = start;
        start = start->next;

        delete temp;
        size--;
        return val;
    }

    int peek()
    {
        if (start == nullptr)
        {
            return -1;
        }
        return start->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    LinkedListQueue q;

    // List of commands
    vector<string> commands = {"LinkedListQueue", "push", "push",
                               "peek", "pop", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i)
    {
        if (commands[i] == "push")
        {
            q.push(inputs[i][0]);
            cout << "null ";
        }
        else if (commands[i] == "pop")
        {
            cout << q.pop() << " ";
        }
        else if (commands[i] == "peek")
        {
            cout << q.peek() << " ";
        }
        else if (commands[i] == "isEmpty")
        {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        }
        else if (commands[i] == "LinkedListQueue")
        {
            cout << "null ";
        }
    }

    return 0;
}